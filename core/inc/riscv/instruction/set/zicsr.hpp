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
			namespace zicsr
			{
				class csrrw: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					csrrw(): base(id_t::csrrw) {}
					csrrw(word_t word): base(id_t::csrrw, word) {}
				};

				class csrrs: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					csrrs(): base(id_t::csrrs) {}
					csrrs(word_t word): base(id_t::csrrs, word) {}
				};

				class csrrc: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					csrrc(): base(id_t::csrrc) {}
					csrrc(word_t word): base(id_t::csrrc, word) {}
				};

				class csrrwi: public basic<format::base::i>
				{
				public:
					using base = basic<format::base::i>;

					csrrwi(): base(id_t::csrrwi) {}
					csrrwi(word_t word): base(id_t::csrrwi, word) {}
				};

				class csrrsi: public basic<format::base::i>
				{
				public:
					using base = basic<format::base::i>;

					csrrsi(): base(id_t::csrrsi) {}
					csrrsi(word_t word): base(id_t::csrrsi, word) {}
				};

				class csrrci: public basic<format::base::i>
				{
				public:
					using base = basic<format::base::i>;

					csrrci(): base(id_t::csrrci) {}
					csrrci(word_t word): base(id_t::csrrci, word) {}
				};
			}
		}
	}
}
