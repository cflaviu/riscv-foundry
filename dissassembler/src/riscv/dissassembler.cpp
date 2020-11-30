#ifndef PCH
    #include "riscv/dissassembler.hpp"
    #include "riscv/instruction/id.hpp"
    #include "riscv/instruction/raw_items.hpp"
    #include "riscv/instruction/identification.hpp"
    #include "riscv/instruction/type.hpp"
    #include "riscv/instruction/raw_items.hpp"
    #include "riscv/instruction/set/rv32a.hpp"
    #include "riscv/instruction/set/rv32d.hpp"
    #include "riscv/instruction/set/rv32f.hpp"
    #include "riscv/instruction/set/rv32i.hpp"
    #include "riscv/instruction/set/rv32m.hpp"
    #include "riscv/instruction/set/rv32q.hpp"
    #include "riscv/instruction/set/rv64a.hpp"
    #include "riscv/instruction/set/rv64d.hpp"
    #include "riscv/instruction/set/rv64f.hpp"
    #include "riscv/instruction/set/rv64i.hpp"
    #include "riscv/instruction/set/rv64m.hpp"
    #include "riscv/instruction/set/rv64q.hpp"
    #include "riscv/instruction/set/zicsr.hpp"
    #include <memory>
#endif

namespace riscv
{
	namespace dissassembler
	{
		using iid = instruction::id_t;
		namespace identification = instruction::identification;

		alpha1::alpha1():
			decode_methods_(
			{
				&alpha1::decode_load,
				&alpha1::decode_fence,
				&alpha1::decode_arithmetic_immediate,
				&alpha1::decode_auipc,
				&alpha1::decode_arithmetic_extended,
				&alpha1::decode_store,
				&alpha1::decode_store_extended,
				&alpha1::decode_arithmetic_atomic,
				&alpha1::decode_arithmetic,
				&alpha1::decode_load_unsinged_immediate,
				&alpha1::decode_arithmetic_w,
				&alpha1::decode_floating_point_add,
				&alpha1::decode_floating_point_load,
				&alpha1::decode_floating_point_subtract,
				&alpha1::decode_floating_point_subtract_negated,
				&alpha1::decode_floating_point_add_negated,
				&alpha1::decode_floating_point_arithmetic,
				&alpha1::decode_branch,
				&alpha1::decode_jump_and_link_register,
				&alpha1::decode_jump_and_link,
				&alpha1::decode_extra
			})
		{}

		void alpha1::operator () (const input_t* binary_code_begin, const input_t* binary_code_end)
		{
			instructions_.clear();
			for(; binary_code_begin != binary_code_end; binary_code_begin += 2)
			{
				//std::cout << std::hex << *binary_code_begin << '\n';

				using namespace instruction;
				auto type = type_of(static_cast<opcode_t>(*binary_code_begin));
				if (type)
				{
					auto raw_instruction = *binary_code_begin;
					//std::cout << std::hex << raw_instruction << '\n';
					(this->*decode_methods_[+*type])(raw_instruction);
				}
			}
		}

		void alpha1::decode_load(word_t word)
		{
			instruction::i_raw raw(word);
			auto type = identification::load(raw().fid());
			if (type)
			{
				namespace load = instruction::set::rv32i::load;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::lb:  add<load::lb>(word); break;
					case iid::lh:  add<load::lh>(word); break;
					case iid::lw:  add<load::lw>(word); break;
					case iid::lbu: add<load::lbu>(word); break;
					case iid::lhu: add<load::lhu>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_fence(word_t word)
		{
			instruction::i_raw raw(word);
			auto type = identification::fence(raw().fid());
			if (type)
			{
				namespace rv32i = instruction::set::rv32i;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fence:    add<rv32i::fence>(word); break;
					case iid::fence_i:  add<rv32i::fence_i>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_arithmetic_immediate(word_t word)
		{
			instruction::raw<instruction::format::base::i> raw(word);
			auto type = identification::arithmentic::immediate(raw().fid());
			if (type)
			{
				namespace arith = instruction::set::rv32i::arithmetic;
				namespace logic = instruction::set::rv32i::logic;
				namespace shift = instruction::set::rv32i::shift;
				namespace set_less_than = instruction::set::rv32i::set_less_than;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::addi:  add<arith::addi>(word); break;
					case iid::andi:  add<logic::andi>(word); break;
					case iid::ori:   add<logic::ori>(word); break;
					case iid::slli:  add<shift::slli>(word); break;
					case iid::slti:  add<set_less_than::slti>(word); break;
					case iid::sltiu: add<set_less_than::sltiu>(word); break;
					case iid::srai:  add<shift::srai>(word); break;
					case iid::srli:  add<shift::slli>(word); break;
					case iid::xori:  add<logic::xori>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_auipc(word_t word)
		{
			add<instruction::set::rv32i::auipc>(word);
		}

		void alpha1::decode_arithmetic_extended(word_t word)
		{
			instruction::raw<instruction::format::base::i> raw(word);
			auto type = identification::arithmentic::extended(raw().fid());
			if (type)
			{
				namespace arith = instruction::set::rv64i::arithmetic;
				namespace shift = instruction::set::rv64i::shift;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::addiw: add<arith::addiw>(word); break;
					case iid::slliw: add<shift::sraiw>(word); break;
					case iid::sraiw: add<shift::sraiw>(word); break;
					case iid::srliw: add<shift::srliw>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_store(word_t word)
		{
			instruction::raw<instruction::format::base::s> raw(word);
			auto type = identification::store(raw().fid());
			if (type)
			{
				namespace store = instruction::set::rv32i::store;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::sb: add<store::sb>(word); break;
					case iid::sd: add<store::sh>(word); break;
					case iid::sh: add<store::sh>(word); break;
					case iid::sw: add<store::sw>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_store_extended(word_t word)
		{
			instruction::raw<instruction::format::base::s> raw(word);
			auto type = identification::store_extended(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fsd: add<rv32d::fsd>(word); break;
					case iid::fsq: add<rv32f::fsq>(word); break;
					case iid::fsw: add<rv32f::fsw>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_arithmetic_atomic(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::arithmentic::atomic(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::amoadd_d:  add<rv64a::arithmentic::amoadd_d>(word); break;
					case iid::amoadd_w:  add<rv32a::arithmentic::amoadd_w>(word); break;
					case iid::amoand_d:  add<rv64a::logic::amoand_d>(word); break;
					case iid::amoand_w:  add<rv32a::logic::amoand_w>(word); break;
					case iid::amomax_d:  add<rv64a::arithmentic::amomax_d>(word); break;
					case iid::amomax_w:  add<rv32a::arithmentic::amomax_w>(word); break;
					case iid::amomaxu_d: add<rv64a::arithmentic::amomaxu_d>(word); break;
					case iid::amomaxu_w: add<rv32a::arithmentic::amomaxu_w>(word); break;
					case iid::amomin_d:  add<rv64a::arithmentic::amomin_d>(word); break;
					case iid::amomin_w:  add<rv32a::arithmentic::amomin_w>(word); break;
					case iid::amominu_d: add<rv64a::arithmentic::amominu_d>(word); break;
					case iid::amominu_w: add<rv32a::arithmentic::amominu_w>(word); break;
					case iid::amoor_d :  add<rv64a::logic::amoor_d>(word); break;
					case iid::amoor_w :  add<rv32a::logic::amoor_w>(word); break;
					case iid::amoswap_d: add<rv64a::amoswap_d>(word); break;
					case iid::amoswap_w: add<rv32a::amoswap_w>(word); break;
					case iid::amoxor_d:  add<rv64a::logic::amoxor_d>(word); break;
					case iid::amoxor_w:  add<rv32a::logic::amoxor_w>(word); break;
					case iid::lr_d:      add<rv64a::lr_d>(word); break;
					case iid::lr_w:      add<rv32a::lr_w>(word); break;
					case iid::sc_d:      add<rv64a::sc_d>(word); break;
					case iid::sc_w:      add<rv32a::sc_w>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_arithmetic(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::arithmentic::basic(raw().fid());
			if (type)
			{
				namespace division = instruction::set::rv32m::division;
				namespace multiplication = instruction::set::rv32m::multiplication;
				namespace logic = instruction::set::rv32i::logic;
				namespace arithmetic = instruction::set::rv32i::arithmetic;
				namespace set_less_than = instruction::set::rv32i::set_less_than;
				namespace shift = instruction::set::rv32i::shift;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::add:    add<arithmetic::add>(word); break;
					case iid::and_:   add<logic::and_>(word); break;
					case iid::div:    add<division::div>(word); break;
					case iid::divu:   add<division::divu>(word); break;
					case iid::mul:    add<multiplication::mul>(word); break;
					case iid::mulh:   add<multiplication::mulh>(word); break;
					case iid::mulhsu: add<multiplication::mulhsu>(word); break;
					case iid::mulhu:  add<multiplication::mulhu>(word); break;
					case iid::or_:    add<logic::or_>(word); break;
					case iid::rem:    add<division::rem>(word); break;
					case iid::remu:   add<division::remu>(word); break;
					case iid::sll:    add<shift::sll>(word); break;
					case iid::slt:    add<set_less_than::slt>(word); break;
					case iid::sltu:   add<set_less_than::sltu>(word); break;
					case iid::sra:    add<shift::sra>(word); break;
					case iid::srl:    add<shift::srl>(word); break;
					case iid::sub:    add<arithmetic::sub>(word); break;
					case iid::xor_:   add<logic::xor_>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_load_unsinged_immediate(word_t word)
		{
			add<instruction::set::rv32i::load::lui>(word);
		}

		void alpha1::decode_arithmetic_w(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::arithmentic::w(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::addw:  add<rv64i::arithmetic::addw>(word); break;
					case iid::divuw: add<rv64m::division::divuw>(word); break;
					case iid::divw:  add<rv64m::division::divw>(word); break;
					case iid::mulw:  add<rv64m::multiplication::mulw>(word); break;
					case iid::remuw: add<rv64m::division::remuw>(word); break;
					case iid::remw:  add<rv64m::division::remw>(word); break;
					case iid::sllw:  add<rv64i::shift::sllw>(word); break;
					case iid::sraw:  add<rv64i::shift::sraw>(word); break;
					case iid::srlw:  add<rv64i::shift::srlw>(word); break;
					case iid::subw:  add<rv64i::arithmetic::subw>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_add(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::floating_point::add(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fmadd_d: add<rv32d::arithmetic::fmadd_d>(word); break;
					case iid::fmadd_q: add<rv32f::arithmetic::fmadd_q>(word); break;
					case iid::fmadd_s: add<rv32f::arithmetic::fmadd_s>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_load(word_t word)
		{
			instruction::i_raw raw(word);
			auto type = identification::floating_point::load(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fld: add<rv32d::fld>(word); break;
					case iid::flq: add<rv32f::flq>(word); break;
					case iid::flw: add<rv32f::flw>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_subtract(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::floating_point::add(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fmsub_d: add<rv32d::arithmetic::fmsub_d>(word); break;
					case iid::fmsub_q: add<rv32f::arithmetic::fmsub_q>(word); break;
					case iid::fmsub_s: add<rv32f::arithmetic::fmsub_s>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_subtract_negated(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::floating_point::subtract_negated(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fnmsub_d: add<rv32d::arithmetic::fnmsub_d>(word); break;
					case iid::fnmsub_q: add<rv32f::arithmetic::fnmsub_q>(word); break;
					case iid::fnmsub_s: add<rv32f::arithmetic::fnmsub_s>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_add_negated(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::floating_point::add_negated(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fnmadd_d: add<rv32d::arithmetic::fnmadd_d>(word); break;
					case iid::fnmadd_q: add<rv32f::arithmetic::fnmadd_q>(word); break;
					case iid::fnmadd_s: add<rv32f::arithmetic::fnmadd_s>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_floating_point_arithmetic(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::floating_point::arithmetic(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::fadd_d:     add<rv32d::arithmetic::fadd_d>(word); break;
					case iid::fadd_q:     add<rv32f::arithmetic::fadd_q>(word); break;
					case iid::fadd_s:     add<rv32f::arithmetic::fadd_s>(word); break;
					case iid::fclass_d:   add<rv32d::fclass_d>(word); break;
					case iid::fclass_q:   add<rv32f::fclass_q>(word); break;
					case iid::fclass_s:   add<rv32f::fclass_s>(word); break;
					case iid::fcvt_d_l:   add<rv64d::conversion::fcvt_d_l>(word); break;
					case iid::fcvt_d_lu:  add<rv64d::conversion::fcvt_d_lu>(word); break;
					case iid::fcvt_d_q:   add<rv32f::conversion::fcvt_d_q>(word); break;
					case iid::fcvt_d_s:   add<rv32d::conversion::fcvt_d_s>(word); break;
					case iid::fcvt_d_w:   add<rv32d::conversion::fcvt_d_w>(word); break;
					case iid::fcvt_d_wu:  add<rv32d::conversion::fcvt_d_wu>(word); break;
					case iid::fcvt_l_d:   add<rv64d::conversion::fcvt_l_d>(word); break;
					case iid::fcvt_l_q:   add<rv64q::conversion::fcvt_l_q>(word); break;
					case iid::fcvt_l_s:   add<rv64f::conversion::fcvt_l_s>(word); break;
					case iid::fcvt_lu_d:  add<rv64d::conversion::fcvt_lu_d>(word); break;
					case iid::fcvt_lu_q:  add<rv64q::conversion::fcvt_lu_q>(word); break;
					case iid::fcvt_lu_s:  add<rv64f::conversion::fcvt_lu_s>(word); break;
					case iid::fcvt_q_d:   add<rv32f::conversion::fcvt_q_d>(word); break;
					case iid::fcvt_q_l:   add<rv64q::conversion::fcvt_q_l>(word); break;
					case iid::fcvt_q_lu:  add<rv64q::conversion::fcvt_q_lu>(word); break;
					case iid::fcvt_q_s:   add<rv32f::conversion::fcvt_q_s>(word); break;
					case iid::fcvt_q_w:   add<rv32f::conversion::fcvt_q_w>(word); break;
					case iid::fcvt_q_wu:  add<rv32f::conversion::fcvt_q_wu>(word); break;
					case iid::fcvt_s_d:   add<rv32d::conversion::fcvt_s_d>(word); break;
					case iid::fcvt_s_l:   add<rv64f::conversion::fcvt_s_l>(word); break;
					case iid::fcvt_s_lu:  add<rv64f::conversion::fcvt_s_lu>(word); break;
					case iid::fcvt_s_q:   add<rv32f::conversion::fcvt_s_q>(word); break;
					case iid::fcvt_s_w:   add<rv32f::conversion::fcvt_s_w>(word); break;
					case iid::fcvt_s_wu:  add<rv32f::conversion::fcvt_s_wu>(word); break;
					case iid::fcvt_w_d:   add<rv32d::conversion::fcvt_w_d>(word); break;
					case iid::fcvt_w_q:   add<rv32f::conversion::fcvt_w_q>(word); break;
					case iid::fcvt_w_s:   add<rv32f::conversion::fcvt_w_s>(word); break;
					case iid::fcvt_wu_d:  add<rv32d::conversion::fcvt_wu_d>(word); break;
					case iid::fcvt_wu_q:  add<rv32f::conversion::fcvt_wu_q>(word); break;
					case iid::fcvt_wu_s:  add<rv32f::conversion::fcvt_wu_s>(word); break;
					case iid::fdiv_d:     add<rv32d::division::fdiv_d>(word); break;
					case iid::fdiv_q:     add<rv32f::division::fdiv_q>(word); break;
					case iid::fdiv_s:     add<rv32f::division::fdiv_s>(word); break;
					case iid::feq_d:      add<rv32d::comparison::feq_d>(word); break;
					case iid::feq_q:      add<rv32f::comparison::feq_q>(word); break;
					case iid::feq_s:      add<rv32f::comparison::feq_s>(word); break;
					case iid::fle_d:      add<rv32d::comparison::fle_d>(word); break;
					case iid::fle_q:      add<rv32f::comparison::fle_q>(word); break;
					case iid::fle_s:      add<rv32f::comparison::fle_s>(word); break;
					case iid::flt_d:      add<rv32d::comparison::flt_d>(word); break;
					case iid::flt_q:      add<rv32f::comparison::flt_q>(word); break;
					case iid::flt_s:      add<rv32f::comparison::flt_s>(word); break;
					case iid::fmax_d:     add<rv32d::arithmetic::fmax_d>(word); break;
					case iid::fmax_q:     add<rv32f::arithmetic::fmax_q>(word); break;
					case iid::fmax_s:     add<rv32f::arithmetic::fmax_s>(word); break;
					case iid::fmin_d:     add<rv32d::arithmetic::fmin_d>(word); break;
					case iid::fmin_q:     add<rv32f::arithmetic::fmin_q>(word); break;
					case iid::fmin_s:     add<rv32f::arithmetic::fmin_s>(word); break;
					case iid::fmul_d:     add<rv32d::multiplication::fmul_d>(word); break;
					case iid::fmul_q:     add<rv32f::multiplication::fmul_q>(word); break;
					case iid::fmul_s:     add<rv32f::multiplication::fmul_s>(word); break;
					case iid::fmv_d_x:    add<rv64d::fmv_d_x>(word); break;
					case iid::fmv_w_x:    add<rv32f::fmv_w_x>(word); break;
					case iid::fmv_x_d:    add<rv64d::fmv_x_d>(word); break;
					case iid::fmv_x_w:    add<rv32f::fmv_x_w>(word); break;
					case iid::fsgnj_d:    add<rv32d::sign::fsgnj_d>(word); break;
					case iid::fsgnj_q:    add<rv32f::sign::fsgnj_q>(word); break;
					case iid::fsgnj_s:    add<rv32f::sign::fsgnj_s>(word); break;
					case iid::fsgnjn_d:   add<rv32d::sign::fsgnjn_d>(word); break;
					case iid::fsgnjn_q:   add<rv32f::sign::fsgnjn_q>(word); break;
					case iid::fsgnjn_s:   add<rv32f::sign::fsgnjn_s>(word); break;
					case iid::fsgnjx_d:   add<rv32d::sign::fsgnjx_d>(word); break;
					case iid::fsgnjx_q:   add<rv32f::sign::fsgnjx_q>(word); break;
					case iid::fsgnjx_s:   add<rv32f::sign::fsgnjx_s>(word); break;
					case iid::fsqrt_d:    add<rv32d::fsqrt_d>(word); break;
					case iid::fsqrt_q:    add<rv32f::fsqrt_q>(word); break;
					case iid::fsqrt_s:    add<rv32f::fsqrt_s>(word); break;
					case iid::fsub_d:     add<rv32d::arithmetic::fsub_d>(word); break;
					case iid::fsub_q:     add<rv32f::arithmetic::fsub_q>(word); break;
					case iid::fsub_s:     add<rv32f::arithmetic::fsub_s>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_branch(word_t word)
		{
			instruction::raw<instruction::format::base::b> raw(word);
			auto type = identification::branch(raw().fid());
			if (type)
			{
				namespace branch = instruction::set::rv32i::branch;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::beq:  add<branch::beq>(word); break;
					case iid::bge:  add<branch::bge>(word); break;
					case iid::bgeu: add<branch::bgeu>(word); break;
					case iid::blt:  add<branch::blt>(word); break;
					case iid::bltu: add<branch::bltu>(word); break;
					case iid::bne:  add<branch::bne>(word); break;
					default:;
				}
			}
		}

		void alpha1::decode_jump_and_link_register(word_t word)
		{
			add<instruction::set::rv32i::jump::jalr>(word);
		}

		void alpha1::decode_jump_and_link(word_t word)
		{
			add<instruction::set::rv32i::jump::jal>(word);
		}

		void alpha1::decode_extra(word_t word)
		{
			instruction::raw<instruction::format::base::r> raw(word);
			auto type = identification::extra(raw().fid());
			if (type)
			{
				using namespace instruction::set;
				std::unique_ptr<instruction::item> instruction;
				switch (*type)
				{
					case iid::csrrw:  add<zicsr::csrrw>(word); break;
					case iid::csrrs:  add<zicsr::csrrs>(word); break;
					case iid::csrrc:  add<zicsr::csrrc>(word); break;
					case iid::csrrwi: add<zicsr::csrrwi>(word); break;
					case iid::csrrsi: add<zicsr::csrrsi>(word); break;
					case iid::csrrci: add<zicsr::csrrci>(word); break;
					case iid::ebreak: add<rv32i::ebreak>(word); break;
					case iid::ecall:  add<rv32i::ecall>(word); break;
					default:;
				}
			}
		}
	}
}
