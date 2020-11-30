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
			namespace rv64d
			{
				namespace conversion
				{
					class fcvt_l_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_l_d(): base(id_t::fcvt_l_d) {}
						fcvt_l_d(word_t word): base(id_t::fcvt_l_d, word) {}
					};

					class fcvt_lu_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_lu_d(): base(id_t::fcvt_lu_d) {}
						fcvt_lu_d(word_t word): base(id_t::fcvt_lu_d, word) {}
					};


					class fcvt_d_l: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_l(): base(id_t::fcvt_d_l) {}
						fcvt_d_l(word_t word): base(id_t::fcvt_d_l, word) {}
					};

					class fcvt_d_lu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_lu(): base(id_t::fcvt_d_lu) {}
						fcvt_d_lu(word_t word): base(id_t::fcvt_d_lu, word) {}
					};
				}

				class fmv_x_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fmv_x_d(): base(id_t::fmv_x_d) {}
					fmv_x_d(word_t word): base(id_t::fmv_x_d, word) {}
				};

				class fmv_d_x: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fmv_d_x(): base(id_t::fmv_d_x) {}
					fmv_d_x(word_t word): base(id_t::fmv_d_x, word) {}
				};
			}
		}
	}
}
