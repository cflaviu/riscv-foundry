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
			namespace rv64m
			{
				namespace division
				{
					class divw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						divw(): base(id_t::divw) {}
						divw(word_t word): base(id_t::divw, word) {}
					};

					class divuw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						divuw(): base(id_t::divuw) {}
						divuw(word_t word): base(id_t::divuw, word) {}
					};

					class remw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						remw(): base(id_t::remw) {}
						remw(word_t word): base(id_t::remw, word) {}
					};

					class remuw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						remuw(): base(id_t::remuw) {}
						remuw(word_t word): base(id_t::remuw, word) {}
					};
				}

				namespace multiplication
				{
					class mulw: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						mulw(): base(id_t::mulw) {}
						mulw(word_t word): base(id_t::mulw, word) {}
					};
				}
			}
		}
	}
}
