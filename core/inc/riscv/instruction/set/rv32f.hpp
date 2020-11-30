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
			namespace rv32f
			{
				namespace arithmetic
				{
					class fmadd_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmadd_s(): base(id_t::fmadd_s) {}
						fmadd_s(word_t word): base(id_t::fmadd_s, word) {}
					};

					class fmsub_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmsub_s(): base(id_t::fmsub_s) {}
						fmsub_s(word_t word): base(id_t::fmsub_s, word) {}
					};

					class fnmsub_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmsub_s(): base(id_t::fnmsub_s) {}
						fnmsub_s(word_t word): base(id_t::fnmsub_s, word) {}
					};

					class fnmadd_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmadd_s(): base(id_t::fnmadd_s) {}
						fnmadd_s(word_t word): base(id_t::fnmadd_s, word) {}
					};

					class fadd_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fadd_s(): base(id_t::fadd_s) {}
						fadd_s(word_t word): base(id_t::fadd_s, word) {}
					};

					class fsub_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsub_s(): base(id_t::fsub_s) {}
						fsub_s(word_t word): base(id_t::fsub_s, word) {}
					};

					class fmin_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmin_s(): base(id_t::fmin_s) {}
						fmin_s(word_t word): base(id_t::fmin_s, word) {}
					};

					class fmax_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmax_s(): base(id_t::fmax_s) {}
						fmax_s(word_t word): base(id_t::fmax_s, word) {}
					};
				}

				namespace conversion
				{
					class fcvt_w_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_w_s(): base(id_t::fcvt_w_s) {}
						fcvt_w_s(word_t word): base(id_t::fcvt_w_s, word) {}
					};

					class fcvt_wu_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_wu_s(): base(id_t::fcvt_wu_s) {}
						fcvt_wu_s(word_t word): base(id_t::fcvt_wu_s, word) {}
					};

					class fcvt_s_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_w(): base(id_t::fcvt_s_w) {}
						fcvt_s_w(word_t word): base(id_t::fcvt_s_w, word) {}
					};

					class fcvt_s_wu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_wu(): base(id_t::fcvt_s_wu) {}
						fcvt_s_wu(word_t word): base(id_t::fcvt_s_wu, word) {}
					};
				}

				namespace comparison
				{
					class feq_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						feq_s(): base(id_t::feq_s) {}
						feq_s(word_t word): base(id_t::feq_s, word) {}
					};

					class flt_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						flt_s(): base(id_t::flt_s) {}
						flt_s(word_t word): base(id_t::flt_s, word) {}
					};

					class fle_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fle_s(): base(id_t::fle_s) {}
						fle_s(word_t word): base(id_t::fle_s, word) {}
					};
				}

				namespace division
				{
					class fdiv_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fdiv_s(): base(id_t::fdiv_s) {}
						fdiv_s(word_t word): base(id_t::fdiv_s, word) {}
					};
				}

				namespace multiplication
				{
					class fmul_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmul_s(): base(id_t::fmul_s) {}
						fmul_s(word_t word): base(id_t::fmul_s, word) {}
					};
				}

				namespace sign
				{
					class fsgnj_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnj_s(): base(id_t::fsgnj_s) {}
						fsgnj_s(word_t word): base(id_t::fsgnj_s, word) {}
					};

					class fsgnjn_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjn_s(): base(id_t::fsgnjn_s) {}
						fsgnjn_s(word_t word): base(id_t::fsgnjn_s, word) {}
					};

					class fsgnjx_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjx_s(): base(id_t::fsgnjx_s) {}
						fsgnjx_s(word_t word): base(id_t::fsgnjx_s, word) {}
					};
				}

				class fclass_s: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fclass_s(): base(id_t::fclass_s) {}
					fclass_s(word_t word): base(id_t::fclass_s, word) {}
				};

				class flw: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					flw(): base(id_t::flw) {}
					flw(word_t word): base(id_t::flw, word) {}
				};

				class fsw: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsw(): base(id_t::fsw) {}
					fsw(word_t word): base(id_t::fsw, word) {}
				};

				class fsqrt_s: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsqrt_s(): base(id_t::fsqrt_s) {}
					fsqrt_s(word_t word): base(id_t::fsqrt_s, word) {}
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
