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
			namespace rv64q
			{
				namespace conversion
				{
					class fcvt_l_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_l_q(): base(id_t::fcvt_l_q) {}
						fcvt_l_q(word_t word): base(id_t::fcvt_l_q, word) {}
					};

					class fcvt_lu_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_lu_q(): base(id_t::fcvt_lu_q) {}
						fcvt_lu_q(word_t word): base(id_t::fcvt_lu_q, word) {}
					};

					class fcvt_q_l: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_l(): base(id_t::fcvt_q_l) {}
						fcvt_q_l(word_t word): base(id_t::fcvt_q_l, word) {}
					};

					class fcvt_q_lu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_lu(): base(id_t::fcvt_q_lu) {}
						fcvt_q_lu(word_t word): base(id_t::fcvt_q_lu, word) {}
					};
				}
			}
		}
	}
}
