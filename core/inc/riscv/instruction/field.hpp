#pragma once
#ifndef PCH
	#include <riscv/basic_types.hpp>
	#include <array>
#endif

namespace riscv
{
	namespace instruction
	{
		namespace field
		{
			enum class opcode: opcode_t
			{
				i  = 0b0000011, // 0x03
				s  = 0b0100011, // 0x23
				r  = 0b0110011, // 0x33
				u  = 0b0110111, // 0x37
				b  = 0b1100011, // 0x63
				j  = 0b1101111, // 0x6f

				auipc = 0b0010111, // 0x17
				fence = 0b0001111, // 0x0f
			};

			enum class extension_opcode: opcode_t
			{

			};

			enum class type: byte
			{
				none,
				opcode_7,
				opcode_2,
				funct_2,
				funct_3,
				funct_4,
				funct_5,
				funct_7,
				funct_12,
				imm_1,
				imm_4,
				imm_5,
				imm_6,
				imm_7,
				imm_8,
				imm_10,
				imm_12,
				imm_20,
				imm1_1,
				imm1_5,
				imm2_1,
				imm2_5,
				imm2_7,
				jump_target_11,
				offset1_5,
				offset2_5,
				rd_3,
				rd_5,
				rs_5,
				rs1_5,
				rs2_3,
				rs2_5,
				rs3_5,
			};

			using type_array = std::array<type, 8>;

			enum class width_funct3: byte
			{
				signed_byte			= 0b000,
				unsigned_byte		= 0b100,
				signed_half_word	= 0b001,
				unsigned_half_word	= 0b101,
				word				= 0b010,
			};

			enum class funct3: byte
			{
				add,
				addi,
				addiw,
				and_,
				andi,
				eq	= 0b000,
				ne	= 0b001,
				lt	= 0b100,
				ge	= 0b101,
				ltu	= 0b110,
				geu	= 0b111,
				or_,
				ori,
				sll,
				slli,
				slliw,
				slt,
				slti,
				sltiu,
				sltu,
				sra,
				srai,
				sraiw,
				srl,
				srli,
				srliw,
				srlli,
				sub,
				xor_,
				xori,
				mul,
				mulh,
				mulhs,
				mulhsu,
				mulw,
				div,
				divu,
				divw,
				divuw,
				rem,
				remu,
				remw,
				remuw,
				csrrw,
				csrrs,
				csrrc,
				csrrwi,
				csrrsi,
				csrrci,
			};

			enum class funct5: byte
			{
				fadd,
				fsub,
				fmul,
				fdiv,
				fmin_max,
				fsqrt,
				fcvt,
				fsgnj,
				fmv,
				fmvx,
				fcmp,
			};

			enum class funct12: byte
			{
				muldiv,
				scall,
				sbreak,
			};

			enum class crs: byte
			{
				rdcycle,
				rdcycle_h,
				rdtime,
				rdtime_h,
				rdinstret,
				rdinstret_h,
			};

			enum class rm: byte
			{
				rm_,
				eq,
				lt,
				le,
				min_max,
				j,
				jn,
				jx,
			};

			enum class rd_bit: byte
			{
				neg_inf,
				neg_normal_no,
				neg_subnormal_no,
				neg_0,
				pos_0,
				pos_normal_no,
				pos_subnormal_no,
				pos_inf,
				signaling_nan,
				quiet_nan,
			};

			enum class null: byte
			{
				rd = 0,
				rs = 0,
				imm = 0,
			};
		}
	}
}
