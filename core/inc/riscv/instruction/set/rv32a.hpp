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
			namespace rv32a
			{
				namespace arithmentic
				{
					//
					class amoadd_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoadd_w(): base(id_t::amoadd_w) {}
						amoadd_w(word_t word): base(id_t::amoadd_w, word) {}
					};

					//
					class amomin_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomin_w(): base(id_t::amomin_w) {}
						amomin_w(word_t word): base(id_t::amomin_w, word) {}
					};

					//
					class amomax_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomax_w(): base(id_t::amomax_w) {}
						amomax_w(word_t word): base(id_t::amomax_w, word) {}
					};

					//
					class amominu_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amominu_w(): base(id_t::amominu_w) {}
						amominu_w(word_t word): base(id_t::amominu_w, word) {}
					};

					//
					class amomaxu_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomaxu_w(): base(id_t::amomaxu_w) {}
						amomaxu_w(word_t word): base(id_t::amomaxu_w, word) {}
					};
				}

				namespace logic
				{
					//
					class amoxor_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoxor_w(): base(id_t::amoxor_w) {}
						amoxor_w(word_t word): base(id_t::amoxor_w, word) {}
					};

					//
					class amoand_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoand_w(): base(id_t::amoand_w) {}
						amoand_w(word_t word): base(id_t::amoand_w, word) {}
					};

					//
					class amoor_w: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoor_w(): base(id_t::amoor_w) {}
						amoor_w(word_t word): base(id_t::amoor_w, word) {}
					};
				}

				//
				class lr_w: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					lr_w(): base(id_t::lr_w) {}
					lr_w(word_t word): base(id_t::lr_w, word) {}
				};

				//
				class sc_w: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					sc_w(): base(id_t::sc_w) {}
					sc_w(word_t word): base(id_t::sc_w, word) {}
				};

				//
				class amoswap_w: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					amoswap_w(): base(id_t::amoswap_w) {}
					amoswap_w(word_t word): base(id_t::amoswap_w, word) {}
				};
			}
		}
	}
}
