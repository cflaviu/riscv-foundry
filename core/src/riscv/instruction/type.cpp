#ifndef PCH
	#include "riscv/instruction/type.hpp"
	#include <unordered_map>
#endif

namespace riscv
{
	namespace instruction
	{
		std::optional<type> type_of(opcode_t item) noexcept
		{
			static const std::unordered_map<opcode_t, type> map
			{
				{ 0x3, type::load },
				// LB  - RV32I Base Instruction Set
				// LBU - RV32I Base Instruction Set
				// LD  - RV64I Base Instruction Set
				// LH  - RV32I Base Instruction Set
				// LHU - RV32I Base Instruction Set
				// LW  - RV32I Base Instruction Set
				// LWU - RV64I Base Instruction Set

				{ 0x7, type::load_floating_point },
				// FLD - RV32D Standard Extension
				// FLQ - RV32Q Standard Extension
				// FLW - RV32F Standard Extension

				{ 0xf, type::fence },
				// FENCE   - RV32I Base Instruction Set
				// FENCE.I - RV32/RV64 Zifencei Standard Extension

				{ 0x13, type::arithmetic_immediate },
				// ADDI  - RV32I Base Instruction Set
				// ANDI  - RV32I Base Instruction Set
				// ORI   - RV32I Base Instruction Set
				// SLLI  - RV32I Base Instruction Set
				// SLTI  - RV32I Base Instruction Set
				// SLTIU - RV32I Base Instruction Set
				// SRAI  - RV32I Base Instruction Set
				// SRAI  - RV64I Base Instruction Set
				// SRLI  - RV64I Base Instruction Set
				// XORI  - RV32I Base Instruction Set

				{ 0x17, type::auipc },
				// AUIPC - RV32I Base Instruction Set

				{ 0x1b, type::arithmetic_extended },
				// ADDIW - RV64I Base Instruction Set
				// SLLIW - RV64I Base Instruction Set
				// SRAIW - RV64I Base Instruction Set
				// SRLIW - RV64I Base Instruction Set

				{ 0x23, type::store },
				// SB - RV32I Base Instruction Set
				// SD - RV64I Base Instruction Set
				// SH - RV32I Base Instruction Set
				// SW - RV32I Base Instruction Set

				{ 0x27, type::store_extended },
				// FSD - RV32D Standard Extension
				// FSQ - RV32Q Standard Extension
				// FSW - RV32F Standard Extension

				{ 0x2f, type::arithmetic_atomic },
				// AMOADD.D  - RV64A Standard Extension
				// AMOADD.W  - RV32A Standard Extension
				// AMOAND.D  - RV64A Standard Extension
				// AMOAND.W  - RV32A Standard Extension
				// AMOMAX.D  - RV64A Standard Extension
				// AMOMAX.W  - RV32A Standard Extension
				// AMOMAXU.D - RV64A Standard Extension
				// AMOMAXU.W - RV32A Standard Extension
				// AMOMIN.D  - RV64A Standard Extension
				// AMOMIN.W  - RV32A Standard Extension
				// AMOMINU.D - RV64A Standard Extension
				// AMOMINU.W - RV32A Standard Extension
				// AMOOR.D   - RV64A Standard Extension
				// AMOOR.W   - RV32A Standard Extension
				// AMOSWAP.D - RV64A Standard Extension
				// AMOSWAP.W - RV32A Standard Extension
				// AMOXOR.D  - RV64A Standard Extension
				// AMOXOR.W  - RV32A Standard Extension
				// LR.D      - RV64A Standard Extension
				// LR.W      - RV32A Standard Extension
				// SC.D      - RV64A Standard Extension
				// SC.W      - RV32A Standard Extension

				{ 0x33, type::arithmetic },
				// ADD    - RV32I Base Instruction Set
				// AND    - RV32I Base Instruction Set
				// DIV    - RV32M Standard Extension
				// DIVU   - RV32M Standard Extension
				// MUL    - RV32M Standard Extension
				// MULH   - RV32M Standard Extension
				// MULHSU - RV32M Standard Extension
				// MULHU  - RV32M Standard Extension
				// OR     - RV32I Base Instruction Set
				// REM    - RV32M Standard Extension
				// REMU   - RV32M Standard Extension
				// SLL    - RV32I Base Instruction Set
				// SLT    - RV32I Base Instruction Set
				// SLTU   - RV32I Base Instruction Set
				// SRA    - RV32I Base Instruction Set
				// SRL    - RV32I Base Instruction Set
				// SUB    - RV32I Base Instruction Set
				// XOR    - RV32I Base Instruction Set

				{ 0x37, type::load_unsinged_immediate },
				// LUI - RV32I Base Instruction Set

				{ 0x3b, type::arithmetic_w },
				// ADDW  - RV64I Base Instruction Set
				// DIVUW - RV64M Standard Extension
				// DIVW  - RV64M Standard Extension
				// MULW  - RV64M Standard Extension
				// REMUW - RV64M Standard Extension
				// REMW  - RV64M Standard Extension
				// SLLW  - RV64I Base Instruction Set
				// SRAW  - RV64I Base Instruction Set
				// SRLW  - RV64I Base Instruction Set
				// SUBW  - RV64I Base Instruction Set

				{ 0x43, type::floating_point_add },
				// FMADD.D - RV32D Standard Extension
				// FMADD.Q - RV32Q Standard Extension
				// FMADD.S - RV32F Standard Extension

				{ 0x47, type::floating_point_subtract },
				// FMSUB.D - RV32D Standard Extension
				// FMSUB.Q - RV32Q Standard Extension
				// FMSUB.S - RV32F Standard Extension

				{ 0x4b, type::floating_point_subtract_negated },
				// FNMSUB.D - RV32D Standard Extension
				// FNMSUB.Q - RV32Q Standard Extension
				// FNMSUB.S - RV32F Standard Extension

				{ 0x4f, type::floating_point_add_negated },
				// FNMADD.D - RV32D Standard Extension
				// FNMADD.Q - RV32Q Standard Extension
				// FNMADD.S - RV32F Standard Extension

				{ 0x53, type::floating_point_arithmetic },
				// FADD.D    - RV32D Standard Extension
				// FADD.Q    - RV32Q Standard Extension
				// FADD.S    - RV32F Standard Extension
				// FCLASS.D  - RV32D Standard Extension
				// FCLASS.Q  - RV32Q Standard Extension
				// FCLASS.S  - RV32F Standard Extension
				// FCVT.D.L  - RV64D Standard Extension
				// FCVT.D.LU - RV64D Standard Extension
				// FCVT.D.Q  - RV32Q Standard Extension
				// FCVT.D.S  - RV32D Standard Extension
				// FCVT.D.W  - RV32D Standard Extension
				// FCVT.D.WU - RV32D Standard Extension
				// FCVT.L.D  - RV64D Standard Extension
				// FCVT.L.Q  - RV64Q Standard Extension
				// FCVT.L.S  - RV64F Standard Extension
				// FCVT.LU.D - RV64D Standard Extension
				// FCVT.LU.Q - RV64Q Standard Extension
				// FCVT.LU.S - RV64F Standard Extension
				// FCVT.Q.D  - RV32Q Standard Extension
				// FCVT.Q.L  - RV64Q Standard Extension
				// FCVT.Q.LU - RV64Q Standard Extension
				// FCVT.Q.S  - RV32Q Standard Extension
				// FCVT.Q.W  - RV32Q Standard Extension
				// FCVT.Q.WU - RV32Q Standard Extension
				// FCVT.S.D  - RV32D Standard Extension
				// FCVT.S.L  - RV64F Standard Extension
				// FCVT.S.LU - RV64F Standard Extension
				// FCVT.S.Q  - RV32Q Standard Extension
				// FCVT.S.W  - RV32F Standard Extension
				// FCVT.S.WU - RV32F Standard Extension
				// FCVT.W.D  - RV32D Standard Extension
				// FCVT.W.Q  - RV32Q Standard Extension
				// FCVT.W.S  - RV32F Standard Extension
				// FCVT.WU.D - RV32D Standard Extension
				// FCVT.WU.Q - RV32Q Standard Extension
				// FCVT.WU.S - RV32F Standard Extension
				// FDIV.D    - RV32D Standard Extension
				// FDIV.Q    - RV32Q Standard Extension
				// FDIV.S    - RV32F Standard Extension
				// FEQ.D     - RV32D Standard Extension
				// FEQ.Q     - RV32Q Standard Extension
				// FEQ.S     - RV32F Standard Extension
				// FLE.D     - RV32D Standard Extension
				// FLE.Q     - RV32Q Standard Extension
				// FLE.S     - RV32F Standard Extension
				// FLT.D     - RV32D Standard Extension
				// FLT.Q     - RV32Q Standard Extension
				// FLT.S     - RV32F Standard Extension
				// FMAX.D    - RV32D Standard Extension
				// FMAX.Q    - RV32Q Standard Extension
				// FMAX.S    - RV32F Standard Extension
				// FMIN.D    - RV32D Standard Extension
				// FMIN.Q    - RV32Q Standard Extension
				// FMIN.S    - RV32F Standard Extension
				// FMUL.D    - RV32D Standard Extension
				// FMUL.Q    - RV32Q Standard Extension
				// FMUL.S    - RV32F Standard Extension
				// FMV.D.X   - RV64D Standard Extension
				// FMV.W.X   - RV32F Standard Extension
				// FMV.X.D   - RV64D Standard Extension
				// FMV.X.W   - RV32F Standard Extension
				// FSGNJ.D   - RV32D Standard Extension
				// FSGNJ.Q   - RV32Q Standard Extension
				// FSGNJ.S   - RV32F Standard Extension
				// FSGNJN.D  - RV32D Standard Extension
				// FSGNJN.Q  - RV32Q Standard Extension
				// FSGNJN.S  - RV32F Standard Extension
				// FSGNJX.D  - RV32D Standard Extension
				// FSGNJX.Q  - RV32Q Standard Extension
				// FSGNJX.S  - RV32F Standard Extension
				// FSQRT.D   - RV32D Standard Extension
				// FSQRT.Q   - RV32Q Standard Extension
				// FSQRT.S   - RV32F Standard Extension
				// FSUB.D    - RV32D Standard Extension
				// FSUB.Q    - RV32Q Standard Extension
				// FSUB.S    - RV32F Standard Extension

				{ 0x63, type::branch },
				// BEQ  - RV32I Base Instruction Set
				// BGE  - RV32I Base Instruction Set
				// BGEU - RV32I Base Instruction Set
				// BLT  - RV32I Base Instruction Set
				// BLTU - RV32I Base Instruction Set
				// BNE  - RV32I Base Instruction Set

				{ 0x67, type::jump_and_link_register },
				// JALR - RV32I Base Instruction Set

				{ 0x6f, type::jump_and_link },
				// JAL - RV32I Base Instruction Set

				{ 0x73, type::extra },
				// CSRRC  - RV32/RV64 Zicsr Standard Extension
				// CSRRCI - RV32/RV64 Zicsr Standard Extension
				// CSRRS  - RV32/RV64 Zicsr Standard Extension
				// CSRRSI - RV32/RV64 Zicsr Standard Extension
				// CSRRW  - RV32/RV64 Zicsr Standard Extension
				// CSRRWI - RV32/RV64 Zicsr Standard Extension
				// EBREAK - RV32I Base Instruction Set
				// ECALL  - RV32I Base Instruction Set
			};

			auto pos = map.find(item);
			return pos != map.end() ? std::make_optional(pos->second) : std::optional<type>();
		}

		std::optional<type> type_of(word_t item) noexcept
		{
			return type_of(static_cast<opcode_t>(item));
		}
	}
}
