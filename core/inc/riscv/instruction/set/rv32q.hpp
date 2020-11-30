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
					class fmadd_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmadd_q(): base(id_t::fmadd_q) {}
						fmadd_q(word_t word): base(id_t::fmadd_q, word) {}
					};

					class fmsub_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmsub_q(): base(id_t::fmsub_q) {}
						fmsub_q(word_t word): base(id_t::fmsub_q, word) {}
					};

					class fnmsub_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmsub_q(): base(id_t::fnmsub_q) {}
						fnmsub_q(word_t word): base(id_t::fnmsub_q, word) {}
					};

					class fnmadd_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fnmadd_q(): base(id_t::fnmadd_q) {}
						fnmadd_q(word_t word): base(id_t::fnmadd_q, word) {}
					};

					class fadd_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fadd_q(): base(id_t::fadd_q) {}
						fadd_q(word_t word): base(id_t::fadd_q, word) {}
					};

					class fsub_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsub_q(): base(id_t::fsub_q) {}
						fsub_q(word_t word): base(id_t::fsub_q, word) {}
					};

					class fmin_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmin_q(): base(id_t::fmin_q) {}
						fmin_q(word_t word): base(id_t::fmin_q, word) {}
					};

					class fmax_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmax_q(): base(id_t::fmax_q) {}
						fmax_q(word_t word): base(id_t::fmax_q, word) {}
					};
				}

				namespace conversion
				{
					class fcvt_s_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_s_q(): base(id_t::fcvt_s_q) {}
						fcvt_s_q(word_t word): base(id_t::fcvt_s_q, word) {}
					};

					class fcvt_q_s: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_s(): base(id_t::fcvt_q_s) {}
						fcvt_q_s(word_t word): base(id_t::fcvt_q_s, word) {}
					};

					class fcvt_d_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_d_q(): base(id_t::fcvt_d_q) {}
						fcvt_d_q(word_t word): base(id_t::fcvt_d_q, word) {}
					};

					class fcvt_q_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_d(): base(id_t::fcvt_q_d) {}
						fcvt_q_d(word_t word): base(id_t::fcvt_q_d, word) {}
					};

					class fcvt_w_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_w_q(): base(id_t::fcvt_w_q) {}
						fcvt_w_q(word_t word): base(id_t::fcvt_w_q, word) {}
					};

					class fcvt_wu_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_wu_q(): base(id_t::fcvt_wu_q) {}
						fcvt_wu_q(word_t word): base(id_t::fcvt_wu_q, word) {}
					};

					class fcvt_q_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_w(): base(id_t::fcvt_q_w) {}
						fcvt_q_w(word_t word): base(id_t::fcvt_q_w, word) {}
					};

					class fcvt_q_wu: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fcvt_q_wu(): base(id_t::fcvt_q_wu) {}
						fcvt_q_wu(word_t word): base(id_t::fcvt_q_wu, word) {}
					};
				}

				namespace comparison
				{
					class feq_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						feq_q(): base(id_t::feq_q) {}
						feq_q(word_t word): base(id_t::feq_q, word) {}
					};

					class flt_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						flt_q(): base(id_t::flt_q) {}
						flt_q(word_t word): base(id_t::flt_q, word) {}
					};

					class fle_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fle_q(): base(id_t::fle_q) {}
						fle_q(word_t word): base(id_t::fle_q, word) {}
					};
				}

				namespace division
				{
					class fdiv_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fdiv_q(): base(id_t::fdiv_q) {}
						fdiv_q(word_t word): base(id_t::fdiv_q, word) {}
					};
				}

				namespace multiplication
				{
					class fmul_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fmul_q(): base(id_t::fmul_q) {}
						fmul_q(word_t word): base(id_t::fmul_q, word) {}
					};
				}

				namespace sign
				{
					class fsgnj_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnj_q(): base(id_t::fsgnj_q) {}
						fsgnj_q(word_t word): base(id_t::fsgnj_q, word) {}
					};

					class fsgnjn_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjn_q(): base(id_t::fsgnjn_q) {}
						fsgnjn_q(word_t word): base(id_t::fsgnjn_q, word) {}
					};

					class fsgnjx_q: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						fsgnjx_q(): base(id_t::fsgnjx_q) {}
						fsgnjx_q(word_t word): base(id_t::fsgnjx_q, word) {}
					};
				}

				class fclass_q: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fclass_q(): base(id_t::fclass_q) {}
					fclass_q(word_t word): base(id_t::fclass_q, word) {}
				};

				class flq: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					flq(): base(id_t::flq) {}
					flq(word_t word): base(id_t::flq, word) {}
				};

				class fsq: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsq(): base(id_t::fsq) {}
					fsq(word_t word): base(id_t::fsq, word) {}
				};

				class fsqrt_q: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					fsqrt_q(): base(id_t::fsqrt_q) {}
					fsqrt_q(word_t word): base(id_t::fsqrt_q, word) {}
				};
			}
		}
	}
}
