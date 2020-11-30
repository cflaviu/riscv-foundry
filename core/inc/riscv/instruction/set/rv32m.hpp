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
			namespace rv32m
			{
				namespace division
				{
					class div: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						div(): base(id_t::div) {}
						div(word_t word): base(id_t::div, word) {}
					};

					class divu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						divu(): base(id_t::divu) {}
						divu(word_t word): base(id_t::divu, word) {}
					};

					class rem: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						rem(): base(id_t::rem) {}
						rem(word_t word): base(id_t::rem, word) {}
					};

					class remu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						remu(): base(id_t::remu) {}
						remu(word_t word): base(id_t::remu, word) {}
					};
				}

				namespace multiplication
				{
					class mul: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						mul(): base(id_t::mul) {}
						mul(word_t word): base(id_t::mul, word) {}
					};

					class mulh: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						mulh(): base(id_t::mulh) {}
						mulh(word_t word): base(id_t::mulh, word) {}
					};

					class mulhsu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						mulhsu(): base(id_t::mulhsu) {}
						mulhsu(word_t word): base(id_t::mulhsu, word) {}
					};

					class mulhu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						mulhu(): base(id_t::mulhu) {}
						mulhu(word_t word): base(id_t::mulhu, word) {}
					};
				}
			}
		}
	}
}
