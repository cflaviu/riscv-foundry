#pragma once
#ifndef PCH
    #include <cstdint>
    #include <unordered_map>
    #include <vector>
    #include <fstream>
#include <iostream>
    #include <boost/iostreams/device/mapped_file.hpp>
#endif

namespace riscv
{
    namespace executable
    {
        namespace elf
        {
            struct traits_32b
            {
                using half_t = std::uint16_t;
                using offset_t = std::uint32_t;
                using address_t = std::uint32_t;
                using word_t = std::uint32_t;
                using signed_word_t = std::int32_t;
                using section_t = std::uint16_t;

                struct program_segment_header
                {
                    word_t      type;
                    offset_t	offset;
                    address_t	virtual_address;
                    address_t   physical_address;
                    word_t      size_in_file;
                    word_t      size_in_memory;
                    word_t      flags;
                    word_t      align;
                };

                struct symbol
                {
                    word_t name;
                    address_t value;
                    word_t size;
                    unsigned char info;
                    unsigned char visibility;
                    section_t section_index;
                };
            };

            struct traits_64b
            {
                using half_t = std::uint16_t;
                using offset_t = std::uint64_t;
                using address_t = std::uint64_t;
                using word_t = std::uint32_t;
                using dword_t = std::uint64_t;
                using signed_word_t = std::int32_t;
                using section_t = std::uint16_t;

                struct program_segment_header
                {
                    word_t type;
                    word_t flags;
                    offset_t offset;
                    address_t virtual_address;
                    address_t physical_address;
                    dword_t size_in_file;
                    dword_t size_in_memory;
                    dword_t align;
                };

                struct symbol
                {
                    word_t name;
                    unsigned char info;
                    unsigned char visibility;
                    section_t section_index;
                    address_t value;
                    word_t size;
                };
            };

            template <typename traits>
            class loader
            {
            public:
                using half_t = typename traits::half_t;
                using offset_t = typename traits::offset_t;
                using address_t = typename traits::address_t;
                using word_t = typename traits::word_t;
                using signed_word_t = typename traits::signed_word_t;
                using program_segment_header_t = typename traits::program_segment_header;
                using program_segment_header_array = std::vector<const program_segment_header_t*>;
                using symbol_map = std::unordered_map<const char*, const typename traits::symbol*>;

                const program_segment_header_array& program_segment_headers() const noexcept { return program_segment_headers_; }

                const symbol_map& symbols() const noexcept { return symbols_; }

                enum class error: std::uint8_t
                {
                    none,
                    file_not_open,
                    wrong_segment_size,
                    too_many_sections,
                    no_segments,
                    fail_reading_segment
                };

                static constexpr size_t max_file_size = 512 * 1024 * 1024; // 512 MiB
                static constexpr half_t max_section_count = 30;

                address_t memory_end() const noexcept { return memory_end_; }

                address_t heap_address() const noexcept { return heap_address_; }

                address_t entry_point() const noexcept { return entry_point_; }

                void load(const char* file_path, std::uint8_t* buffer, address_t buffer_size, address_t offset = 0)
                {
                    try
                    {
                        open_file(file_path);
                        check_header();
                        read_program_segments();
                        read_sections(buffer, buffer_size, offset);
                    }
                    catch(error e)
                    {
                        reset();
                        throw e;
                    }
                }

                void load_virtual(const char* file_path, std::uint8_t* buffer, address_t buffer_size, address_t offset = 0)
                {
                    try
                    {
                        open_file(file_path);
                        check_header();
                        read_program_segments();
                        read_sections_virtual(buffer, buffer_size, offset);
                    }
                    catch(error e)
                    {
                        reset();
                        throw e;
                    }
                }

            protected:
                enum class program_segment_type: word_t
                {
                    null,
                    load,
                    dynamic,
                    interp,
                    note,
                    shlib,
                    phdr,
                    tls,
                    num
                };

                struct elf_header
                {
                    static constexpr unsigned indentifier_size() noexcept { return 16; }

                    uint8_t indentifier[indentifier_size()];
                    half_t type;
                    half_t machine;
                    word_t version;
                    address_t entry_point;
                    offset_t program_header_table_offset;
                    offset_t section_header_table_offset;
                    word_t flags;
                    half_t header_size;
                    half_t program_header_entry_size;
                    half_t program_header_entry_count;
                    half_t section_header_entry_size;
                    half_t section_header_entry_count;
                    half_t section_header_string_table_index;
                };

                struct section_header
                {
                    word_t name;
                    word_t type;
                    word_t flags;
                    address_t address;
                    offset_t offset;
                    word_t size;
                    word_t link;
                    word_t info;
                    word_t address_align;
                    word_t entry_size;
                };

                const std::uint8_t* begin() const { return reinterpret_cast<const std::uint8_t*>(file_.data()); }

                void open_file(const char* file_path)
                {
                    file_.open(file_path, max_file_size);
                    if (!file_.is_open())
                    {
                        throw error::file_not_open;
                    }
                }

                void check_header()
                {
                    elf_header_ = reinterpret_cast<const elf_header*>(begin());
                    if (sizeof(program_segment_header_t) != elf_header_->program_header_entry_size)
                    {
                        throw error::wrong_segment_size;
                    }

                    if (elf_header_->program_header_entry_count > max_section_count)
                    {
                        throw error::too_many_sections;
                    }

                    entry_point_ = elf_header_->entry_point;
                }

                void read_program_segments()
                {
                    program_segment_headers_.clear();
                    program_segment_headers_.reserve(elf_header_->program_header_entry_count);
                    auto* segment = reinterpret_cast<const program_segment_header_t*>(begin() + elf_header_->program_header_table_offset);
                    const auto program_header_entry_count = elf_header_->program_header_entry_count;
                    for (auto count = program_header_entry_count; count-- != 0; ++segment)
                    {
                        if (segment->type == +program_segment_type::load)
                        {
                            program_segment_headers_.push_back(segment);
                        }
                    }

                    if (program_segment_headers_.empty())
                    {
                        throw error::no_segments;
                    }

                    auto last_program_header = reinterpret_cast<const program_segment_header_t*>(begin() +
                        elf_header_->program_header_table_offset + elf_header_->program_header_entry_size * (program_header_entry_count - 1));
                    memory_end_ = last_program_header->virtual_address + last_program_header->size_in_memory;
                    heap_address_ = memory_end_ + memory_end_% 8;
                }

                void read_sections(std::uint8_t* buffer, address_t size, address_t offset)
                {
                    for(auto program_segment_header : program_segment_headers_)
                    {
                        auto size_in_file = program_segment_header->size_in_file;
                        if (size_in_file != 0)
                        {
                            auto limit = offset + size;
                            auto physical_address = program_segment_header->physical_address;
                            auto size_in_memory = program_segment_header->size_in_memory;

                            if ((physical_address < offset) || (physical_address + size_in_memory >= limit))
                            {
                                throw error::fail_reading_segment;
                            }

                            std::memcpy(buffer + physical_address - offset, begin() + program_segment_header->offset, size_in_file);
                        }
                    }
                }

                void read_sections_virtual(std::uint8_t* buffer, address_t size, address_t offset)
                {
                    for(auto program_segment_header : program_segment_headers_)
                    {
                        auto size_in_file = program_segment_header->size_in_file;
                        if (size_in_file != 0)
                        {
                            auto virtual_address = program_segment_header->virtual_address;
                            auto size_in_memory = program_segment_header->size_in_memory;

//                            if (offset == 0)
//                            {
//                                offset = virtual_address;
//                            }

                            if ((virtual_address < offset) || (virtual_address + size_in_memory >= offset + size))
                            {
                                throw error::fail_reading_segment;
                            }

                            std::memcpy(buffer + virtual_address - offset, begin() + program_segment_header->offset, size_in_file);
                        }
                    }
                }

                void reset() noexcept
                {
                    file_.close();
                    elf_header_ = nullptr;
                    program_segment_headers_.clear();
                    symbols_.clear();
                    memory_end_ = 0;
                    heap_address_ = 0;
                    entry_point_ = 0;
                }

                boost::iostreams::mapped_file_source file_;
                const elf_header* elf_header_ = nullptr;
                program_segment_header_array program_segment_headers_;
                symbol_map symbols_;
                address_t memory_end_ = 0;
                address_t heap_address_ = 0;
                address_t entry_point_ = 0;
            };

            using loader_32b = loader<traits_32b>;
            using loader_64b = loader<traits_64b>;
        }
    }
}
