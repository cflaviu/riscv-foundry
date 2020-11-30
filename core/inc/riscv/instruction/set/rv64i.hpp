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
			namespace rv64i
			{
				namespace arithmetic
				{
					// add immediate
					class addiw: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						addiw(): base(id_t::addiw) {}
						addiw(word_t word): base(id_t::addiw, word) {}
					};

					// add immediate
					class addw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						addw(): base(id_t::addw) {}
						addw(word_t word): base(id_t::addw, word) {}
					};

					// add immediate
					class subw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						subw(): base(id_t::subw) {}
						subw(word_t word): base(id_t::subw, word) {}
					};
				}

				namespace load
				{
					//
					class ld: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						ld(): base(id_t::ld) {}
						ld(word_t word): base(id_t::ld, word) {}
					};

					//
					class lwu: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						lwu(): base(id_t::lwu) {}
						lwu(word_t word): base(id_t::lwu, word) {}
					};
				}

				namespace store
				{
					//
					class sd: public basic<format::base::s>
					{
					public:
						using base = basic<format::base::s>;

						sd(): base(id_t::sd) {}
						sd(word_t word): base(id_t::sd, word) {}
					};
				}

				namespace shift
				{
					// add immediate
					class sllw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sllw(): base(id_t::sllw) {}
						sllw(word_t word): base(id_t::sllw, word) {}
					};

					// exclusive or immediate
					class slliw: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						slliw(): base(id_t::slliw) {}
						slliw(word_t word): base(id_t::slliw, word) {}
					};

					// add immediate
					class sraw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						sraw(): base(id_t::sraw) {}
						sraw(word_t word): base(id_t::sraw, word) {}
					};

					// exclusive or immediate
					class sraiw: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						sraiw(): base(id_t::sraiw) {}
						sraiw(word_t word): base(id_t::sraiw, word) {}
					};

					// add immediate
					class srlw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						srlw(): base(id_t::srlw) {}
						srlw(word_t word): base(id_t::srlw, word) {}
					};

					// exclusive or immediate
					class srliw: public basic<format::base::i>
					{
					public:
						using base = basic<format::base::i>;

						srliw(): base(id_t::srliw) {}
						srliw(word_t word): base(id_t::srliw, word) {}
					};
				}
			}
		}
	}
}
