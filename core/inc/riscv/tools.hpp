#pragma once
#ifndef PCH
    #include <cstdint>
#endif

namespace riscv
{
    namespace tools
    {
        std::uint32_t circular_shift(std::uint32_t value, std::uint32_t shift = 32);

    }
}
