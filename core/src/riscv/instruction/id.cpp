#ifndef PCH
	#include "riscv/instruction/id.hpp"
#endif

namespace riscv
{
	namespace instruction
	{
		const char* text_of(id_t id)
		{
			static const char* const texts[] =
			{
				// RV32I Base Instruction Set
				"lui",
				"auipc",
				"jal",
				"jalr",
				"beq",
				"bne",
				"blt",
				"bge",
				"bltu",
				"bgeu",
				"lb",
				"lh",
				"lw",
				"lbu",
				"lhu",
				"sb",
				"sh",
				"sw",
				"addi",
				"slti",
				"sltiu",
				"xori",
				"ori",
				"andi",
				"slli",
				"srli",
				"srai",
				"add",
				"sub",
				"sll",
				"slt",
				"sltu",
				"xor",
				"srl",
				"sra",
				"or",
				"and",
				"fence",
				"ecall",
				"ebreak",

				// RV64I Base Instruction Set
				"lwu",
				"ld",
				"sd",
				//			slli",
				//			srli",
				//			srai",
				"addiw",
				"slliw",
				"srliw",
				"sraiw",
				"addw",
				"subw",
				"sllw",
				"srlw",
				"sraw",

				// RV32/RV64 Zifencei Standard Extension
				"fence.i",

				// RV32/RV64 Zicsr Standard Extensio
				"csrrw",
				"csrrs",
				"csrrc",
				"csrrwi",
				"csrrsi",
				"csrrci",

				// RV32M Standard Extension
				"mul",
				"mulh",
				"mulhsu",
				"mulhu",
				"div",
				"divu",
				"rem",
				"remu",

				// RV64M Standard Extension
				"mulw",
				"divw",
				"divuw",
				"remw",
				"remuw",

				// RV32A Standard Extension
				"lr.w",
				"sc.w",
				"amoswap.w",
				"amoadd.w",
				"amoxor.w",
				"amoand.w",
				"amoor.w",
				"amomin.w",
				"amomax.w",
				"amominu.w",
				"amomaxu.w",

				// RV64A Standard Extension
				"lr.d",
				"sc.d",
				"amoswap.d",
				"amoadd.d",
				"amoxor.d",
				"amoand.d",
				"amoor.d",
				"amomin.d",
				"amomax.d",
				"amominu.d",
				"amomaxu.d",

				// RV32F Standard Extension
				"flw",
				"fsw",
				"fmadd.s",
				"fmsub.s",
				"fnmsub.s",
				"fnmadd.s",
				"fadd.s",
				"fsub.s",
				"fmul.s",
				"fdiv.s",
				"fsqrt.s",
				"fsgnj.s",
				"fsgnjn.s",
				"fsgnjx.s",
				"fmin.s",
				"fmax.s",
				"fcvt.w.s",
				"fcvt.wu.s",
				"fmv.x.w",
				"feq.s",
				"flt.s",
				"fle.s",
				"fclass.s",
				"fcvt.s.w",
				"fcvt.s.wu",
				"fmv.w.x",

				// RV64F Standard Extension
				"fcvt.l.s",
				"fcvt.lu.s",
				"fcvt.s.l",
				"fcvt.s.lu",

				// RV32D Standard Extension
				"fld",
				"fsd",
				"fmadd.d",
				"fmsub.d",
				"fnmsub.d",
				"fnmadd.d",
				"fadd.d",
				"fsub.d",
				"fmul.d",
				"fdiv.d",
				"fsqrt.d",
				"fsgnj.d",
				"fsgnjn.d",
				"fsgnjx.d",
				"fmin.d",
				"fmax.d",
				"fcvt.s.d",
				"fcvt.d.s",
				"feq.d",
				"flt.d",
				"fle.d",
				"fclass.d",
				"fcvt.w.d",
				"fcvt.wu.d",
				"fcvt.d.w",
				"fcvt.d.wu",

				// RV64D Standard Extension
				"fcvt.l.d",
				"fcvt.lu.d",
				"fmv.x.d",
				"fcvt.d.l",
				"fcvt.d.lu",
				"fmv.d.x",

				// RV32Q Standard Extension
				"flq",
				"fsq",
				"fmadd.q",
				"fmsub.q",
				"fnmsub.q",
				"fnmadd.q",
				"fadd.q",
				"fsub.q",
				"fmul.q",
				"fdiv.q",
				"fsqrt.q",
				"fsgnj.q",
				"fsgnjn.q",
				"fsgnjx.q",
				"fmin.q",
				"fmax.q",
				"fcvt.s.q",
				"fcvt.q.s",
				"fcvt.d.q",
				"fcvt.q.d",
				"feq.q",
				"flt.q",
				"fle.q",
				"fclass.q",
				"fcvt.w.q",
				"fcvt.wu.q",
				"fcvt.q.w",
				"fcvt.q.wu",

				// RV64Q Standard Extension
				"fcvt.l.q",
				"fcvt.lu.q",
				"fcvt.q.l",
				"fcvt.q.lu",
			};

			return texts[+id];
		}

		word_t default_word(id_t id)
		{
			return 0;
		}

		std::optional<id_t> load_type(uint16_t id)
		{
			return {};
		}

		std::optional<id_t> store_type(uint16_t id)
		{
			return {};
		}

		std::optional<id_t> load_floating_point_type(uint16_t id)
		{
			return {};
		}
	}
}
