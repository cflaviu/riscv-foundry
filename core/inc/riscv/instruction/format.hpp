#pragma once
#ifndef PCH
	#include <riscv/instruction/field.hpp>
	#include <optional>
	#include <tuple>
	#include <iostream>
	#include <functional>
#endif

namespace riscv
{
	using out_stream = std::ostream;

	namespace instruction
	{
		using meta_info_array = field::type_array;

		namespace format
		{
			using function_t = std::uint8_t;
			using register_t = std::uint8_t;
			using immediate8_t = std::int8_t;
			using immediate16_t = std::int16_t;
			using offset_t = std::uint8_t;
			using jump_target_t = std::int16_t;
			using print_function_t = out_stream& (*)(out_stream&, register_t reg_no);

			namespace base
			{
				struct r
				{
					word_t opcode	: 7;
					word_t rd		: 5;
					word_t funct_3	: 3;
					word_t rs1		: 5;
					word_t rs2		: 5;
					word_t funct_7	: 7;

					static constexpr byte field_count() { return 6; }
					static const meta_info_array& meta_info();

                    r() = default;
                    r(const opcode_t oc, const function_t funct_3, const function_t funct_7 = 0) noexcept;
                    r(const opcode_t oc, const register_t rd, const function_t funct_3, const register_t rs1, const register_t rs2, const function_t funct_7);

                    std::uint16_t fid() const noexcept
                    {
                        return (funct_3 << 7) | funct_7;
                    }

                    std::uint32_t id() const noexcept
                    {
                        return (opcode << 10) | fid();
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, function_t, register_t, register_t, function_t>(opcode, rd, funct_3, rs1, rs2, funct_7);
                    }

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = funct_3;
                        array[3] = rs1;
                        array[4] = rs2;
                        array[5] = funct_7;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

                struct r4
                {
                    word_t opcode	: 7;
                    word_t rd		: 5;
                    word_t funct_3	: 3;
                    word_t rs1		: 5;
                    word_t rs2		: 5;
                    word_t funct_2	: 2;
                    word_t rs3		: 5;

                    static constexpr byte field_count() { return 7; }
                    static const meta_info_array& meta_info();

                    r4() = default;
                    r4(const opcode_t oc, const function_t funct_3, const function_t funct_2 = 0) noexcept;
                    r4(const opcode_t oc, const register_t rd, const function_t funct_3, const register_t rs1, const register_t rs2, const function_t funct_2, const register_t rs3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return (funct_3 << 2) | funct_2;
                    }

                    std::uint16_t id() const noexcept
                    {
                        return (opcode << 5) | fid();
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, function_t, register_t, register_t, function_t, register_t>(opcode, rd, funct_3, rs1, rs2, funct_2, rs3);
                    }

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = funct_3;
                        array[3] = rs1;
                        array[4] = rs2;
                        array[5] = funct_2;
                        array[6] = rs3;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

                struct i
                {
                    word_t opcode	: 7;
                    word_t rd		: 5;
                    word_t funct_3	: 3;
                    word_t rs		: 5;
                    word_t imm		: 12;

                    static constexpr byte field_count() { return 5; }
                    static const meta_info_array& meta_info();

                    i() = default;
                    i(const opcode_t oc, const function_t funct_3 = 0, const immediate16_t imm = 0) noexcept;
                    i(const opcode_t opcode, const register_t rd, const function_t funct_3, const register_t rs, const immediate16_t imm) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint16_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, function_t, register_t, immediate16_t>(opcode, rd, funct_3, rs, imm);
                    }

                    signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = funct_3;
                        array[3] = rs;
                        array[4] = imm;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                    out_stream& print_load(out_stream& out, const std::string& opcode, print_function_t printer) const;
                };

                struct s
                {
                    word_t opcode	: 7;
                    word_t imm_a    : 5;
                    word_t funct_3	: 3;
                    word_t rs1		: 5;
                    word_t rs2		: 5;
                    word_t imm_b    : 7;

                    static constexpr byte field_count() { return 6; }
                    static const meta_info_array& meta_info();

                    s() = default;
                    s(const opcode_t oc, const function_t funct_3, const immediate8_t imm_a = 0, const immediate8_t imm_b = 0) noexcept;
                    s(const opcode_t oc, const immediate8_t imm_a, const function_t funct_3, const register_t rs1, const register_t rs2, const immediate8_t imm_b) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint16_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, function_t, register_t, register_t, immediate8_t>(opcode, imm_a, funct_3, rs1, rs2, imm_b);
                    }

                    signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = imm_a;
                        array[2] = funct_3;
                        array[3] = rs1;
                        array[4] = rs2;
                        array[5] = imm_b;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

                struct b
                {
                    word_t opcode	: 7;
                    word_t imm_a	: 1;
                    word_t imm_b	: 4;
                    word_t funct_3	: 3;
                    word_t rs1		: 5;
                    word_t rs2		: 5;
                    word_t imm_c	: 6;
                    word_t imm_d	: 1;

                    static constexpr byte field_count() { return 8; }
                    static const meta_info_array& meta_info();

                    b() = default;
                    b(const opcode_t oc, const function_t funct_3) noexcept;
                    b(const opcode_t oc, const immediate8_t imm_a, const immediate8_t imm_b, const function_t funct_3, const immediate8_t imm_c, const immediate8_t imm_d) noexcept;
                    b(const opcode_t oc, const immediate8_t imm_a, const immediate8_t imm_b, const function_t funct_3, const register_t rs1, const register_t rs2, const immediate8_t imm_c, const immediate8_t imm_d) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint16_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, immediate8_t, immediate8_t, function_t, register_t, register_t, immediate8_t, immediate8_t>(opcode, imm_a, imm_b, funct_3, rs1, rs2, imm_c, imm_d);
                    }

                    signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = imm_a;
                        array[2] = imm_b;
                        array[3] = funct_3;
                        array[4] = rs1;
                        array[5] = rs2;
                        array[6] = imm_c;
                        array[7] = imm_d;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

                struct u
                {
                    word_t opcode	: 7;
                    word_t rd		: 5;
                    word_t imm		: 20;

                    static constexpr byte field_count() { return 3; }
                    static const meta_info_array& meta_info();

                    u() = default;
                    u(const opcode_t oc, const immediate16_t imm = 0) noexcept;
                    u(const opcode_t oc, const register_t rd, const immediate8_t imm) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return 0;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return opcode;
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, immediate8_t>(opcode, rd, imm);
                    }

                    signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = imm;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

                struct j
                {
                    word_t opcode	:  7;
                    word_t rd		:  5;
                    word_t imm_a	:  8;
                    word_t imm_b	:  1;
                    word_t imm_c	: 10;
                    word_t imm_d	:  1;

                    static constexpr byte field_count() { return 6; }
                    static const meta_info_array& meta_info();

                    j() = default;
                    j(const opcode_t oc, const immediate8_t imm_a = 0, const immediate8_t imm_b = 0, const immediate8_t imm_c = 0, const immediate8_t imm_d = 0) noexcept;
                    j(const opcode_t oc, const register_t rd, const immediate8_t imm_a, const immediate8_t imm_b, const immediate8_t imm_c, const immediate8_t imm_d) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return 0;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return opcode;
                    }

                    auto as_tuple() const noexcept
                    {
                        return std::tuple<opcode_t, register_t, immediate8_t, immediate8_t, immediate8_t, immediate8_t>(opcode, rd, imm_a, imm_b, imm_c, imm_d);
                    }

                    signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = imm_a;
                        array[3] = imm_b;
                        array[4] = imm_c;
                        array[5] = imm_d;
                    }

                    out_stream& print(out_stream& out, const char* opcode, print_function_t printer) const;
                };
            }

			namespace extension
			{
				struct cr
				{
					half_word_t opcode	: 2;
					half_word_t rs1		: 5;
					half_word_t rs2		: 5;
					half_word_t funct_4	: 4;

					static constexpr byte field_count() { return 4; }
					static const meta_info_array& meta_info();

					cr() noexcept = default;
					cr(const opcode_t oc, const function_t funct_4) noexcept;
					cr(const opcode_t oc, const register_t rs1, const register_t rs2, const function_t funct_4) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_4;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 4) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, register_t, register_t, function_t>(opcode, rs1, rs2, funct_4);
					}

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rs1;
                        array[2] = rs2;
                        array[3] = funct_4;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct ci
				{
					half_word_t			opcode	: 2;
					signed_half_word_t	imm1	: 5;
					half_word_t			rs1		: 5;
					signed_half_word_t	imm2	: 1;
					half_word_t			funct_3	: 3;

					static constexpr byte field_count() { return 5; }
					static const meta_info_array& meta_info();

					ci() noexcept= default;
					ci(const opcode_t oc, const immediate8_t funct_3) noexcept;
					ci(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const function_t funct_3) noexcept;
					ci(const opcode_t oc, const immediate8_t imm1, const register_t rs1, const immediate8_t imm2, const function_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | funct_3;
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, immediate8_t, register_t, immediate8_t, function_t>(opcode, imm2, rs1, imm2, funct_3);
					}

					signed_word_t immediate1_value() const noexcept;
					signed_word_t immediate2_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = imm1;
                        array[2] = rs1;
                        array[3] = imm2;
                        array[4] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct css
				{
					half_word_t			opcode	: 2;
					half_word_t			rs		: 5;
					signed_half_word_t	imm		: 6;
					half_word_t			funct_3	: 3;

					static constexpr byte field_count() { return 4; }
					static const meta_info_array& meta_info();

					css() = default;
					css(const opcode_t oc, const immediate8_t funct_3) noexcept;
					css(const opcode_t oc, const immediate8_t imm, const immediate8_t funct_3) noexcept;
					css(const opcode_t oc, const register_t rs, const immediate8_t imm, const immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, register_t, immediate8_t, immediate8_t>(opcode, rs, imm, funct_3);
					}

					signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rs;
                        array[2] = imm;
                        array[3] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct ciw
				{
					half_word_t			opcode	: 2;
					half_word_t			rd		: 3;
					signed_half_word_t	imm		: 8;
					half_word_t			funct_3	: 3;

					static constexpr byte field_count() { return 4; }
					static const meta_info_array& meta_info();

					ciw() = default;
					ciw(const opcode_t oc, const immediate8_t funct_3) noexcept;
					ciw(const opcode_t oc, const immediate8_t imm, const immediate8_t funct_3) noexcept;
					ciw(const opcode_t oc, const register_t rd, const immediate8_t imm, const immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, register_t, immediate8_t, immediate8_t>(opcode, rd, imm, funct_3);
					}

					signed_word_t immediate_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rd;
                        array[2] = imm;
                        array[3] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct cl
				{
					half_word_t			opcode	: 2;
					half_word_t			rd		: 3;
					signed_half_word_t	imm1	: 5;
					half_word_t			rs		: 5;
					signed_half_word_t	imm2	: 1;
					half_word_t			funct_3	: 3;

					static constexpr byte field_count() { return 6; }
					static const meta_info_array& meta_info();

					cl() = default;
					cl(const opcode_t oc, const immediate8_t funct_3) noexcept;
					cl(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const immediate8_t funct_3) noexcept;
					cl(const opcode_t oc, const immediate8_t imm1, const register_t rs, const immediate8_t imm2, const immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, immediate8_t, register_t, immediate8_t, immediate8_t>(opcode, imm1, rs, imm2, funct_3);
					}

					signed_word_t immediate1_value() const noexcept;
					signed_word_t immediate2_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = imm1;
                        array[2] = rs;
                        array[3] = imm2;
                        array[4] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct cs
				{
					half_word_t			opcode	: 2;
					half_word_t			rs2		: 3;
					signed_half_word_t	imm2	: 5;
					half_word_t			rs1		: 5;
					signed_half_word_t	imm1	: 1;
					half_word_t			funct_3	: 3;

					static constexpr byte field_count() { return 6; }
					static const meta_info_array& meta_info();

					cs() = default;
					cs(const opcode_t oc, const immediate8_t funct_3) noexcept;
					cs(const opcode_t oc, const immediate8_t imm1, const immediate8_t imm2, const immediate8_t funct_3) noexcept;
					cs(const opcode_t oc, const register_t rs2, const immediate8_t imm1, const register_t rs1, const immediate8_t imm2, const immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, register_t, immediate8_t, register_t, immediate8_t, immediate8_t>(opcode, rs2, imm2, rs1, imm1, funct_3);
					}

					signed_word_t immediate1_value() const noexcept;
					signed_word_t immediate2_value() const noexcept;

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = rs2;
                        array[2] = imm2;
                        array[3] = rs1;
                        array[4] = imm1;
                        array[5] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct cb
				{
					half_word_t	opcode	: 2;
					half_word_t	offset1	: 5;
					half_word_t	rs1		: 3;
					half_word_t	offset2	: 5;
					half_word_t	funct_3	: 3;

					static constexpr byte field_count() { return 5; }
					static const meta_info_array& meta_info();

					cb() = default;
					cb(const opcode_t oc, const immediate8_t funct_3) noexcept;
					cb(const opcode_t oc, const offset_t offset1, const register_t rs1, const offset_t offset2, const immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, offset_t, register_t, offset_t, immediate8_t>(opcode, offset1, rs1, offset2, funct_3);
					}

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = offset1;
                        array[2] = rs1;
                        array[3] = rs1;
                        array[4] = offset2;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };

				struct cj
				{
					half_word_t	opcode		: 2;
					half_word_t	jump_target	: 11;
					half_word_t	funct_3		: 3;

					static constexpr byte field_count() { return 3; }
					static const meta_info_array& meta_info();

					cj() = default;
					cj(const opcode_t oc, immediate8_t funct_3) noexcept;
					cj(const opcode_t oc, const jump_target_t jump_target, immediate8_t funct_3) noexcept;

                    std::uint8_t fid() const noexcept
                    {
                        return funct_3;
                    }

                    std::uint8_t id() const noexcept
                    {
                        return (opcode << 3) | fid();
                    }

					auto as_tuple() const noexcept
					{
						return std::tuple<opcode_t, jump_target_t, immediate8_t>(opcode, jump_target, funct_3);
					}

                    template <typename T>
                    void to_array(T& array) const noexcept
                    {
                        array[0] = opcode;
                        array[1] = jump_target;
                        array[2] = funct_3;
                    }

                    void print(out_stream& out, const char* opcode, print_function_t printer) const;
                };
            }
        }
    }
}
