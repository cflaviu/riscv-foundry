#include "riscv/dissassembler.hpp"
#include "riscv/executable/elf.hpp"
#include <vector>
#include <iostream>

int main(int argc, const char* const argv[])
{
    if (argc == 2)
    {
        const auto file_name = argv[1];
        using namespace riscv;
        try
        {
#if 0
            std::vector<std::uint8_t> buffer(12_MiB);
            executable::elf::loader_64b loader;
            loader.load(file_name, buffer.data(), buffer.size(), 0);
            //loader.load_virtual(file_name, buffer.data(), buffer.size(), 4_MiB);

            //std::ofstream out("/home/io/out_img.bin", std::ios::binary | std::ios::trunc);
            //out.write((const char*)buffer.data(), loader.memory_end());
            //out.close();

            std::cout << "entry-point: " << std::hex << loader.entry_point() << '\n';

            auto begin = reinterpret_cast<const dissassembler::alpha1::input_t*>(buffer.data());
            dissassembler::alpha1 dissassembler;
            dissassembler(begin + loader.entry_point(), begin + loader.memory_end());
#else
            std::ifstream file(file_name, std::ios::binary | std::ios::ate);
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);

            std::vector<std::uint8_t> buffer(size);
            file.read((char*)buffer.data(), size);

            auto begin = reinterpret_cast<const dissassembler::alpha1::input_t*>(buffer.data());
            dissassembler::alpha1 dissassembler;
            dissassembler(begin, begin + (buffer.size() / 4));
#endif
            std::cout << dissassembler.instructions().size() << " instructions loaded\n";

            for(const auto& item : dissassembler.instructions())
            {
                item->print(std::cout);
            }
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        catch(executable::elf::loader_64b::error e)
        {
            std::cout << "error " << int(+e) << '\n';
        }
        catch(...)
        {
            std::cout << "unknwon exception\n";
        }
    }
    else
    {
        std::cout << "param: <riscv-binary-file>\n";
    }

    return 0;
}
