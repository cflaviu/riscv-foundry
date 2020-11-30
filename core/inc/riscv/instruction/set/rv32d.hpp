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
			namespace rv32d
			{
				namespace arithmetic
				{
					class fmadd_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmadd_d(): base(id_t::fmadd_d) {}
						fmadd_d(word_t word): base(id_t::fmadd_d, word) {}
					};

					class fmsub_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmsub_d(): base(id_t::fmsub_d) {}
						fmsub_d(word_t word): base(id_t::fmsub_d, word) {}
					};

					class fnmsub_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmsub_d(): base(id_t::fnmsub_d) {}
						fnmsub_d(word_t word): base(id_t::fnmsub_d, word) {}
					};

					class fnmadd_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmadd_d(): base(id_t::fnmadd_d) {}
						fnmadd_d(word_t word): base(id_t::fnmadd_d, word) {}
					};

					class fadd_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fadd_d(): base(id_t::fadd_d) {}
						fadd_d(word_t word): base(id_t::fadd_d, word) {}
					};

					class fsub_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsub_d(): base(id_t::fsub_d) {}
						fsub_d(word_t word): base(id_t::fsub_d, word) {}
					};

					class fmin_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmin_d(): base(id_t::fmin_d) {}
						fmin_d(word_t word): base(id_t::fmin_d, word) {}
					};

					class fmax_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmax_d(): base(id_t::fmax_d) {}
						fmax_d(word_t word): base(id_t::fmax_d, word) {}
					};
				}

				namespace conversion
				{
					class fcvt_s_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_d(): base(id_t::fcvt_s_d) {}
						fcvt_s_d(word_t word): base(id_t::fcvt_s_d, word) {}
					};

					class fcvt_d_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_s(): base(id_t::fcvt_d_s) {}
						fcvt_d_s(word_t word): base(id_t::fcvt_d_s, word) {}
					};

					class fcvt_w_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_w_d(): base(id_t::fcvt_w_d) {}
						fcvt_w_d(word_t word): base(id_t::fcvt_w_d, word) {}
					};

					class fcvt_wu_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_wu_d(): base(id_t::fcvt_wu_d) {}
						fcvt_wu_d(word_t word): base(id_t::fcvt_wu_d, word) {}
					};

					class fcvt_d_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_w(): base(id_t::fcvt_d_w) {}
						fcvt_d_w(word_t word): base(id_t::fcvt_d_w, word) {}
					};

					class fcvt_d_wu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_wu(): base(id_t::fcvt_d_wu) {}
						fcvt_d_wu(word_t word): base(id_t::fcvt_d_wu, word) {}
					};
				}

				namespace comparison
				{
					class feq_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						feq_d(): base(id_t::feq_d) {}
						feq_d(word_t word): base(id_t::feq_d, word) {}
					};

					class flt_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						flt_d(): base(id_t::flt_d) {}
						flt_d(word_t word): base(id_t::flt_d, word) {}
					};

					class fle_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fle_d(): base(id_t::fle_d) {}
						fle_d(word_t word): base(id_t::fle_d, word) {}
					};
				}

				namespace division
				{
					class fdiv_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fdiv_d(): base(id_t::fdiv_d) {}
						fdiv_d(word_t word): base(id_t::fdiv_d, word) {}
					};
				}

				namespace multiplication
				{
					class fmul_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmul_d(): base(id_t::fmul_d) {}
						fmul_d(word_t word): base(id_t::fmul_d, word) {}
					};
				}

				namespace sign
				{
					class fsgnj_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnj_d(): base(id_t::fsgnj_d) {}
						fsgnj_d(word_t word): base(id_t::fsgnj_d, word) {}
					};

					class fsgnjn_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjn_d(): base(id_t::fsgnjn_d) {}
						fsgnjn_d(word_t word): base(id_t::fsgnjn_d, word) {}
					};

					class fsgnjx_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjx_d(): base(id_t::fsgnjx_d) {}
						fsgnjx_d(word_t word): base(id_t::fsgnjx_d, word) {}
					};
				}

				class fclass_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fclass_d(): base(id_t::fclass_d) {}
					fclass_d(word_t word): base(id_t::fclass_d, word) {}
				};

				class fld: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fld(): base(id_t::fld) {}
					fld(word_t word): base(id_t::fld, word) {}
				};

				class fsd: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsd(): base(id_t::fsd) {}
					fsd(word_t word): base(id_t::fsd, word) {}
				};

				class fsqrt_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsqrt_d(): base(id_t::fsqrt_d) {}
					fsqrt_d(word_t word): base(id_t::fsqrt_d, word) {}
				};

				class fmv_x_w: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fmv_x_w(): base(id_t::fmv_x_w) {}
					fmv_x_w(word_t word): base(id_t::fmv_x_w, word) {}
				};

				class fmv_w_x: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fmv_w_x(): base(id_t::fmv_w_x) {}
					fmv_w_x(word_t word): base(id_t::fmv_w_x, word) {}
				};
			}
		}
	}
}
