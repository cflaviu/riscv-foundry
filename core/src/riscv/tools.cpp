#ifndef PCH
    #include "riscv/tools.hpp"
#endif

namespace riscv
{
    namespace tools
    {
        std::uint32_t circular_shift(std::uint32_t value, std::uint32_t shift)
        {
            return (value << shift) | ((value >> (sizeof(value) * 8 - shift)) & (0x7F >> (sizeof(value) * 8 - shift)));
        }
    }
}
