#pragma once
#ifndef PCH
    #include <riscv/instruction/field.hpp>
    #include <riscv/instruction/format.hpp>
    #include <riscv/instruction/item.hpp>
#endif

namespace riscv
{
	namespace instruction
	{
		namespace set
		{
			namespace rv32i
			{
				namespace arithmetic
				{
					// add upper immedate to pc
					class add: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						add(): base(id_t::add) {}
						add(word_t word): base(id_t::add, word) {}
					};

					// add immediate
					class addi: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						addi(): base(id_t::addi) {}
						addi(word_t word): base(id_t::addi, word) {}
					};

					// substract
					class sub: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sub(): base(id_t::sub) {}
						sub(word_t word): base(id_t::sub, word) {}
					};
				}

				namespace branch
				{
					using sb_imm = basic<format::base::b>;

					class beq: public sb_imm
					{
					public:
						beq(): sb_imm(id_t::beq) {}
						beq(word_t word): sb_imm(id_t::beq, word) {}
					};

					class bne: public sb_imm
					{
					public:
						bne(): sb_imm(id_t::bne) {}
						bne(word_t word): sb_imm(id_t::bne, word) {}
					};

					class blt: public sb_imm
					{
					public:
						blt(): sb_imm(id_t::blt) {}
						blt(word_t word): sb_imm(id_t::blt, word) {}
					};

					class bltu: public sb_imm
					{
					public:
						bltu(): sb_imm(id_t::bltu) {}
						bltu(word_t word): sb_imm(id_t::bltu, word) {}
					};

					class bge: public sb_imm
					{
					public:
						bge(): sb_imm(id_t::bge) {}
						bge(word_t word): sb_imm(id_t::bge, word) {}
					};

					class bgeu: public sb_imm
					{
					public:
						bgeu(): sb_imm(id_t::bgeu) {}
						bgeu(word_t word): sb_imm(id_t::bgeu, word) {}
					};
				}

				namespace jump
				{
					class jal: public basic<format::base::j>
					{
					public:
						using base = basic<format::base::j>;

						jal(): base(id_t::jal) {}
						jal(word_t word): base(id_t::jal, word) {}
					};

					class jalr: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						jalr(): base(id_t::jalr) {}
						jalr(word_t word): base(id_t::jalr, word) {}
					};
				}

				// load
				namespace load
				{
					class lb: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lb(): base(id_t::jalr) {}
						lb(word_t word): base(id_t::jalr, word) {}
					};

					class lbu: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lbu(): base(id_t::lbu) {}
						lbu(word_t word): base(id_t::lbu, word) {}
					};

					class lh: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lh(): base(id_t::lh) {}
						lh(word_t word): base(id_t::lh, word) {}
					};

					class lhu: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lhu(): base(id_t::lhu) {}
						lhu(word_t word): base(id_t::lhu, word) {}
					};

					class lui: public basic<format::base::u>
					{
					public:
						using base = basic<format::base::u>;

						lui(): base(id_t::lui) {}
						lui(word_t word): base(id_t::lui, word) {}
					};

					// @brief Load word
					class lw: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lw(): base(id_t::lw) {}
						lw(word_t word): base(id_t::lw, word) {}
					};
				}

				namespace logic
				{
					// and
					class and_: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						and_(): base(id_t::and_) {}
						and_(word_t word): base(id_t::and_, word) {}
					};

					// and immediate
					class andi: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						andi(): base(id_t::andi) {}
						andi(word_t word): base(id_t::andi, word) {}
					};

					// or
					class or_: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						or_(): base(id_t::or_) {}
						or_(word_t word): base(id_t::or_, word) {}
					};

					// or immediate
					class ori: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						ori(): base(id_t::ori) {}
						ori(word_t word): base(id_t::ori, word) {}
					};

					// exclusive or
					class xor_: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						xor_(): base(id_t::xor_) {}
						xor_(word_t word): base(id_t::xor_, word) {}
					};

					// exclusive or immediate
					class xori: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						xori(): base(id_t::xori) {}
						xori(word_t word): base(id_t::xori, word) {}
					};
				}

				namespace set_less_than
				{
					// exclusive or immediate
					class slt: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						slt(): base(id_t::slt) {}
						slt(word_t word): base(id_t::slt, word) {}
					};

					// exclusive or immediate
					class slti: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						slti(): base(id_t::slti) {}
						slti(word_t word): base(id_t::slti, word) {}
					};

					// exclusive or immediate
					class sltiu: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						sltiu(): base(id_t::sltiu) {}
						sltiu(word_t word): base(id_t::sltiu, word) {}
					};

					// exclusive or immediate
					class sltu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sltu(): base(id_t::sltiu) {}
						sltu(word_t word): base(id_t::sltiu, word) {}
					};
				}

				namespace shift
				{
					// exclusive or immediate
					class sra: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sra(): base(id_t::sra) {}
						sra(word_t word): base(id_t::sra, word) {}
					};

					// exclusive or immediate
					class srai: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						srai(): base(id_t::srai) {}
						srai(word_t word): base(id_t::srai, word) {}
					};

					// exclusive or immediate
					class sll: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sll(): base(id_t::sll) {}
						sll(word_t word): base(id_t::sll, word) {}
					};

					// exclusive or immediate
					class slli: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						slli(): base(id_t::slli) {}
						slli(word_t word): base(id_t::slli, word) {}
					};

					// exclusive or immediate
					class srl: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						srl(): base(id_t::srl) {}
						srl(word_t word): base(id_t::srl, word) {}
					};

					// exclusive or immediate
					class srli: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						srli(): base(id_t::srli) {}
						srli(word_t word): base(id_t::srli, word) {}
					};
				}

				/// @brief store
				namespace store
				{
					/// @brief Store byte
					class sb: public basic<format::base::s>
					{
					public:
						using base = basic<format::base::s>;

						sb(): base(id_t::sb) {}
						sb(word_t word): base(id_t::sb, word) {}
					};

					class sh: public basic<format::base::s>
					{
					public:
						using base = basic<format::base::s>;

						sh(): base(id_t::sh) {}
						sh(word_t word): base(id_t::sh, word) {}
					};

					// store word
					class sw: public basic<format::base::s>
					{
					public:
						using base = basic<format::base::s>;

						sw(): base(id_t::sw) {}
						sw(word_t word): base(id_t::sw, word) {}
					};
				}

				// add upper immedate to pc
				class auipc: public basic<format::base::u>
				{
				public:
					using base = basic<format::base::u>;

					auipc(): base(id_t::auipc) {}
					auipc(word_t word): base(id_t::auipc, word) {}
				};

				//
				class fence: public basic<format::base::u>
				{
				public:
					using base = basic<format::base::u>;

					fence(): base(id_t::fence) {}
					fence(word_t word): base(id_t::fence, word) {}
				};

				//
				class fence_i: public basic<format::base::u>
				{
				public:
					using base = basic<format::base::u>;

					fence_i(): base(id_t::fence_i) {}
					fence_i(word_t word): base(id_t::fence_i, word) {}
				};

				//
				class ebreak: public basic<format::base::u>
				{
				public:
					using base = basic<format::base::u>;

					ebreak(): base(id_t::ebreak) {}
					ebreak(word_t word): base(id_t::ebreak, word) {}
				};

				//
				class ecall: public basic<format::base::u>
				{
				public:
					using base = basic<format::base::u>;

					ecall(): base(id_t::ecall) {}
					ecall(word_t word): base(id_t::ecall, word) {}
				};
			}
		}
	}
}
