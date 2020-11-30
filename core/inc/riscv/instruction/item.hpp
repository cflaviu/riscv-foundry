#pragma once
#ifndef PCH
    #include <riscv/instruction/raw.hpp>
    #include <riscv/instruction/format.hpp>
    #include <riscv/instruction/id.hpp>
    #include <riscv/register.hpp>
#endif

namespace riscv
{
    using out_stream = std::ostream;

    namespace instruction
    {
        using meta_info_array = field::type_array;

        class item
        {
        protected:
            word_t word_;
            id_t id_;

            item(id_t id, word_t word) noexcept : word_(word), id_(id) {}
            item(id_t id) noexcept : item(id, default_word(id)) {}

		public:
			virtual ~item() noexcept = default;

			id_t id() const noexcept { return id_; }

			word_t word() const noexcept { return word_; }

			virtual byte meta_info_size() const noexcept = 0;
			virtual const meta_info_array& meta_info() const noexcept = 0;

			virtual out_stream& print(out_stream& out) const = 0;
		};


        template <typename _Bitfields>
        class basic: public item
        {
        protected:
            using inner_t = raw<_Bitfields>;

            using item::item;

            const inner_t& inner() const noexcept { return reinterpret_cast<const inner_t&>(word_); }
            inner_t& inner() noexcept { return reinterpret_cast<inner_t&>(word_); }

            const _Bitfields& bitfields() const noexcept { return inner()(); }
            _Bitfields& bitfields() noexcept { return inner()(); }

        public:
            byte meta_info_size() const noexcept override { return _Bitfields::field_count(); }
            const meta_info_array& meta_info() const noexcept override { return bitfields().meta_info(); }
            out_stream& print(out_stream& out) const override { return bitfields().print(out, text_of(id_), &register_::print_gpr_abi_register); }
        };
    }
}
