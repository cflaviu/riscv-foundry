#ifndef PCH
	#include "riscv/instruction/format.hpp"
	#include "riscv/instruction/field.hpp"
	#include "riscv/tools.hpp"
	#include <string>
#endif

namespace riscv
{
	namespace instruction
	{
		namespace format
		{
			using function_t = std::uint8_t;
			using register_t = std::uint8_t;
			using immediate8_t = std::int8_t;
			using immediate16_t = std::int16_t;
			using offset_t = std::uint8_t;
			using jump_target_t = std::int16_t;

			static const std::string sep = ", ";

			namespace base
			{
				r::r(const opcode_t oc, const function_t funct_3, const function_t funct_7) noexcept:
					opcode(oc),
					rd(0),
					funct_3(funct_3),
					rs1(0),
					rs2(0),
					funct_7(funct_7)
				{}

                r::r(const opcode_t oc, const register_t rd, const function_t funct_3, const register_t rs1, const register_t rs2, const function_t funct_7):
                    opcode(oc),
                    rd(rd),
                    funct_3(funct_3),
                    rs1(rs1),
                    rs2(rs2),
                    funct_7(funct_7)
                {}

                const meta_info_array& r::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::rd_5,
                        t::funct_3,
                        t::rs1_5,
                        t::rs2_5,
                        t::funct_7,

                        t::none,
                        t::none,
                    };

                    return items;
                }


                r4::r4(const opcode_t oc, const function_t funct_3, const function_t funct_2) noexcept:
                    opcode(oc),
                    rd(0),
                    funct_3(funct_3),
                    rs1(0),
                    rs2(0),
                    funct_2(funct_2),
                    rs3(0)
                {}

                r4::r4(const opcode_t oc, const register_t rd, const function_t funct_3, const register_t rs1, const register_t rs2, const function_t funct_2, const register_t rs3) noexcept:
                    opcode(oc),
                    rd(rd),
                    funct_3(funct_3),
                    rs1(rs1),
                    rs2(rs2),
                    funct_2(funct_2),
                    rs3(rs3)
                {}

                const meta_info_array& r4::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::rd_5,
                        t::funct_3,
                        t::rs1_5,
                        t::rs2_5,
                        t::funct_2,
                        t::rs3_5,

                        t::none
                    };

                    return items;
                }

                out_stream& r::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    printer(out, rd) << sep;
                    printer(out, rs1) << sep;
                    return printer(out, rd) << '\n';
                }


                i::i(const opcode_t oc, const function_t funct_3, const immediate16_t imm) noexcept:
                    opcode(oc),
                    rd(0),
                    funct_3(funct_3),
                    rs(0),
                    imm(imm)
                {}

                i::i(const opcode_t opcode, const register_t rd, const function_t funct_3, const register_t rs, const immediate16_t imm) noexcept:
                    opcode(opcode),
                    rd(rd),
                    funct_3(funct_3),
                    rs(rs),
                    imm(imm)
                {}

                signed_word_t i::immediate_value() const noexcept
                {
                    auto extended_imm = signed_word_t(imm);
                    return (extended_imm & signed_word_t(0x800)) != 0 ? signed_word_t(0xfffff000) | extended_imm : extended_imm & 0x1f;
                }

                const meta_info_array& i::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::rd_5,
                        t::funct_3,
                        t::rs_5,
                        t::imm_12,

                        t::none,
                        t::none
                    };

                    return items;
                }

                out_stream& i::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    printer(out, rd) << sep;
                    printer(out, rs) << sep;
                    auto value = immediate_value();
                    if (abs(value) < 1024)
                    {
                        out << std::showpos << value << std::noshowpos;
                    }
                    else
                    {
                        out << '0' << 'x' << std::hex << value << std::dec;
                    }

                    return out<< '\n';
                }

                out_stream& i::print_load(out_stream& out, const std::string& opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    printer(out, rd) << sep;
                    auto value = immediate_value();
                    if (abs(value) < 1024)
                    {
                        out << std::showpos << value << std::noshowpos;
                    }
                    else
                    {
                        out << '0' << 'x' << std::hex << value << std::dec;
                    }

                    out << '(';
                    return printer(out, rs) << ')' << '\n';
                }


                s::s(const opcode_t oc, const function_t funct_3, const immediate8_t imm_a, const immediate8_t imm_b) noexcept:
                    opcode(oc),
                    imm_a(imm_a),
                    funct_3(funct_3),
                    rs1(0),
                    rs2(0),
                    imm_b(imm_b)
                {}

                s::s(const opcode_t oc, const immediate8_t imm_a, const function_t funct_3, const register_t rs1, const register_t rs2, const immediate8_t imm_b) noexcept:
                    opcode(oc),
                    imm_a(imm_a),
                    funct_3(funct_3),
                    rs1(rs1),
                    rs2(rs2),
                    imm_b(imm_b)
                {}

                signed_word_t s::immediate_value() const noexcept
                {
                    const signed_word_t extended_imm_b = imm_b;
                    return (extended_imm_b << 5) | signed_word_t(imm_a) | ((extended_imm_b & signed_word_t(0x800)) != 0 ? signed_word_t(0xffffff000) : 0);
                }

                const meta_info_array& s::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::imm_5,
                        t::funct_3,
                        t::rs1_5,
                        t::rs2_5,
                        t::imm_7,

                        t::none,
                        t::none
                    };

                    return items;
                }

                out_stream& s::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    printer(out, rs1) << sep << std::showpos << immediate_value() << std::noshowpos << '(';
                    return printer(out, rs2) << ')' << '\n';
                }


                b::b(const opcode_t oc, const function_t funct_3) noexcept:
                    opcode(oc),
                    imm_a(0),
                    imm_b(0),
                    funct_3(funct_3),
                    rs1(0),
                    rs2(0),
                    imm_c(0),
                    imm_d(0)
                {}

                b::b(const opcode_t oc, const immediate8_t imm_a, const immediate8_t imm_b, const function_t funct_3, const immediate8_t imm_c, const immediate8_t imm_d) noexcept:
                    opcode(oc),
                    imm_a(imm_a),
                    imm_b(imm_b),
                    funct_3(funct_3),
                    rs1(0),
                    rs2(0),
                    imm_c(imm_c),
                    imm_d(imm_d)
                {}

                b::b(const opcode_t oc, const immediate8_t imm_a, const immediate8_t imm_b, const function_t funct_3, const register_t rs1, const register_t rs2, const immediate8_t imm_c, const immediate8_t imm_d) noexcept:
                    opcode(oc),
                    imm_a(imm_a),
                    imm_b(imm_b),
                    funct_3(funct_3),
                    rs1(rs1),
                    rs2(rs2),
                    imm_c(imm_c),
                    imm_d(imm_d)
                {}

                signed_word_t b::immediate_value() const noexcept
                {
                    const signed_word_t extended_imm_c = imm_c;
                    auto result = (extended_imm_c << 5) | (signed_word_t(imm_b) << 1) | ((extended_imm_c & signed_word_t(0x800)) != 0 ? signed_word_t(0xffffff000) : 0);
                    if (imm_a != 0)
                    {
                        result |= 0x200;
                    }

                    return result;
                }

                const meta_info_array& b::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::imm_1,
                        t::imm_4,
                        t::funct_3,
                        t::rs1_5,
                        t::rs2_5,
                        t::imm_6,
                        t::imm_1
                    };

                    return items;
                }

                out_stream& b::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    printer(out, rs1) << sep;
                    return printer(out, rs2) << sep << std::showpos << immediate_value() << std::noshowpos << '\n';
                }



                u::u(const opcode_t oc, const immediate16_t imm) noexcept:
                    opcode(oc),
                    rd(0),
                    imm(imm)
                {}

                u::u(const opcode_t oc, const register_t rd, const immediate8_t imm) noexcept:
                    opcode(oc),
                    rd(rd),
                    imm(imm)
                {}

                signed_word_t u::immediate_value() const noexcept
                {
                    return signed_word_t(imm) << 12;
                }

                const meta_info_array& u::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::rd_5,
                        t::imm_20,

                        t::none,
                        t::none,
                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }

                out_stream& u::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    return printer(out, rd) << sep << std::showpos << immediate_value() << std::noshowpos << '\n';
                }


                j::j(const opcode_t oc, const immediate8_t imm_a, const immediate8_t imm_b, const immediate8_t imm_c, const immediate8_t imm_d) noexcept:
                    opcode(oc),
                    rd(0),
                    imm_a(imm_a),
                    imm_b(imm_b),
                    imm_c(imm_c),
                    imm_d(imm_d)
                {}

                j::j(const opcode_t oc, const register_t rd, const immediate8_t imm_a, const immediate8_t imm_b, const immediate8_t imm_c, const immediate8_t imm_d) noexcept:
                    opcode(oc),
                    rd(rd),
                    imm_a(imm_a),
                    imm_b(imm_b),
                    imm_c(imm_c),
                    imm_d(imm_d)
                {}

                signed_word_t j::immediate_value() const noexcept
                {
                    return  signed_word_t(imm_d != 0 ? 0xffe00000 : 0) |
                            (signed_word_t(imm_a) << 11) |
                            (tools::circular_shift((signed_word_t(imm_c) << 1) | signed_word_t(imm_b)) & signed_word_t(~1));
                }

                const meta_info_array& j::meta_info()
                {
                    using t = field::type;
                    static meta_info_array items
                    {
                        t::opcode_7,
                        t::rd_5,
                        t::imm_8,   // a
                        t::imm_1,   // b
                        t::imm_10,  // c
                        t::imm_1,   // d

                        t::none,
                        t::none
                    };

                    return items;
                }

                out_stream& j::print(out_stream& out, const char* opcode, print_function_t printer) const
                {
                    out << opcode << ' ';
                    return printer(out, rd) << sep << std::showpos << immediate_value() << std::noshowpos << '\n';
                }
            }

			namespace extension
			{
				cr::cr(const opcode_t oc, const function_t funct_4) noexcept:
					opcode(oc),
					rs1(0),
					rs2(0),
					funct_4(funct_4)
				{}

				cr::cr(const opcode_t oc, const register_t rs1, const register_t rs2, const function_t funct_4) noexcept:
					opcode(oc),
					rs1(rs1),
					rs2(rs2),
					funct_4(funct_4)
				{}

                const meta_info_array& cr::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_7,
                        t::rs1_5,
                        t::rs2_5,
                        t::funct_4,

                        t::none,
                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }


				ci::ci(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const function_t funct_3) noexcept:
					opcode(oc),
					imm1(imm1),
					imm2(imm2),
					funct_3(funct_3)
				{}

				ci::ci(const opcode_t oc, const immediate8_t imm1, const register_t rs1, const immediate8_t imm2, const function_t funct_3) noexcept:
					opcode(oc),
					imm1(imm1),
					rs1(rs1),
					imm2(imm2),
					funct_3(funct_3)
				{}

                const meta_info_array& ci::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::imm1_5,
                        t::rs1_5,
                        t::imm2_1,
                        t::funct_3,

                        t::none,
                        t::none,
                        t::none,
                    };

                    return items;
                }


				css::css(const opcode_t oc, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs(0),
					imm(0),
					funct_3(funct_3)
				{}

				css::css(const opcode_t oc, const immediate8_t imm, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs(0),
					imm(imm),
					funct_3(funct_3)
				{}

				css::css(const opcode_t oc, const register_t rs, const immediate8_t imm, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs(rs),
					imm(imm),
					funct_3(funct_3)
				{}

                const meta_info_array& css::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::rs_5,
                        t::imm_6,
                        t::funct_3,

                        t::none,
                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }


				ciw::ciw(const opcode_t oc, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rd(0),
					imm(0),
					funct_3(funct_3)
				{}

				ciw::ciw(const opcode_t oc, const immediate8_t imm, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rd(0),
					imm(imm),
					funct_3(funct_3)
				{}

				ciw::ciw(const opcode_t oc, const register_t rd, const immediate8_t imm, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rd(rd),
					imm(imm),
					funct_3(funct_3)
				{}

                const meta_info_array& ciw::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::rd_5,
                        t::imm_8,
                        t::funct_3,

                        t::none,
                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }


				cl::cl(const opcode_t oc, const immediate8_t funct_3) noexcept:
					opcode(oc),
					imm1(0),
					rs(0),
					imm2(0),
					funct_3(funct_3)
				{}

				cl::cl(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const immediate8_t funct_3) noexcept:
					opcode(oc),
					imm1(imm1),
					rs(0),
					imm2(imm2),
					funct_3(funct_3)
				{}

				cl::cl(const opcode_t oc, const immediate8_t imm1, const register_t rs, const immediate8_t imm2, const immediate8_t funct_3) noexcept:
					opcode(oc),
					imm1(imm1),
					rs(rs),
					imm2(imm2),
					funct_3(funct_3)
				{}

                const meta_info_array& cl::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::rd_3,
                        t::imm_5,
                        t::rs_5,
                        t::imm_1,
                        t::funct_3,

                        t::none,
                        t::none
                    };

                    return items;
                }


				cs::cs(const opcode_t oc, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs2(0),
					imm2(0),
					rs1(0),
					imm1(0),
					funct_3(funct_3)
				{}

				cs::cs(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs2(0),
					imm2(imm2),
					rs1(0),
					imm1(imm1),
					funct_3(funct_3)
				{}

				cs::cs(const opcode_t oc, const register_t rs2, const immediate8_t imm1, const register_t rs1, const immediate8_t imm2, const immediate8_t funct_3) noexcept:
					opcode(oc),
					rs2(rs2),
					imm2(imm2),
					rs1(rs1),
					imm1(imm1),
					funct_3(funct_3)
				{}

                const meta_info_array& cs::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::rs2_3,
                        t::imm2_5,
                        t::rs1_5,
                        t::imm1_1,
                        t::funct_3,

                        t::none,
                        t::none
                    };

                    return items;
                }


				cb::cb(const opcode_t oc, const immediate8_t funct_3) noexcept:
					opcode(oc),
					offset1(0),
					rs1(0),
					offset2(0),
					funct_3(funct_3)
				{}

				cb::cb(const opcode_t oc, const offset_t offset1, const register_t rs1, const offset_t offset2, const immediate8_t funct_3) noexcept:
					opcode(oc),
					offset1(offset1),
					rs1(rs1),
					offset2(offset2),
					funct_3(funct_3)
				{}

                const meta_info_array& cb::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::offset1_5,
                        t::rs1_5,
                        t::offset2_5,
                        t::funct_3,

                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }


				cj::cj(const opcode_t oc, immediate8_t funct_3) noexcept:
					opcode(oc),
					jump_target(0),
					funct_3(funct_3)
				{}

				cj::cj(const opcode_t oc, const jump_target_t jump_target, immediate8_t funct_3) noexcept:
					opcode(oc),
					jump_target(jump_target),
					funct_3(funct_3)
				{}

                const meta_info_array& cj::meta_info()
                {
                    using t = field::type;
                    static const meta_info_array items
                    {
                        t::opcode_2,
                        t::jump_target_11,
                        t::funct_3,

                        t::none,
                        t::none,
                        t::none,
                        t::none,
                        t::none
                    };

                    return items;
                }
            }
        }
    }
}
