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
			namespace rv64f
			{
				namespace conversion
				{
					class fcvt_l_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_l_s(): base(id_t::fcvt_l_s) {}
						fcvt_l_s(word_t word): base(id_t::fcvt_l_s, word) {}
					};

					class fcvt_lu_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_lu_s(): base(id_t::fcvt_lu_s) {}
						fcvt_lu_s(word_t word): base(id_t::fcvt_lu_s, word) {}
					};

					class fcvt_s_l: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_l(): base(id_t::fcvt_s_l) {}
						fcvt_s_l(word_t word): base(id_t::fcvt_s_l, word) {}
					};

					class fcvt_s_lu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_lu(): base(id_t::fcvt_s_lu) {}
						fcvt_s_lu(word_t word): base(id_t::fcvt_s_lu, word) {}
					};
				}
			}
		}
	}
}
