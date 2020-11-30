#pragma once
#ifndef PCH
    #include <riscv/instruction/raw.hpp>
    #include <riscv/instruction/format.hpp>
#endif

namespace riscv
{
    namespace instruction
    {
        using b_raw = raw<format::base::b>;
        using i_raw = raw<format::base::i>;
        using j_raw = raw<format::base::j>;
        using r_raw = raw<format::base::r>;
        using s_raw = raw<format::base::s>;
        using u_raw = raw<format::base::u>;
    }
}
