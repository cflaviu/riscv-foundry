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
			namespace rv64a
			{
				namespace arithmentic
				{
					//
					class amoadd_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoadd_d(): base(id_t::amoadd_d) {}
						amoadd_d(word_t word): base(id_t::amoadd_d, word) {}
					};

					//
					class amomin_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomin_d(): base(id_t::amomin_d) {}
						amomin_d(word_t word): base(id_t::amomin_d, word) {}
					};

					//
					class amomax_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomax_d(): base(id_t::amomax_d) {}
						amomax_d(word_t word): base(id_t::amomax_d, word) {}
					};

					//
					class amominu_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amominu_d(): base(id_t::amominu_d) {}
						amominu_d(word_t word): base(id_t::amominu_d, word) {}
					};

					//
					class amomaxu_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amomaxu_d(): base(id_t::amomaxu_d) {}
						amomaxu_d(word_t word): base(id_t::amomaxu_d, word) {}
					};
				}

				namespace logic
				{
					//
					class amoxor_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoxor_d(): base(id_t::amoxor_d) {}
						amoxor_d(word_t word): base(id_t::amoxor_d, word) {}
					};

					//
					class amoand_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoand_d(): base(id_t::amoand_d) {}
						amoand_d(word_t word): base(id_t::amoand_d, word) {}
					};

					//
					class amoor_d: public basic<format::base::r>
					{
					public:
						using base = basic<format::base::r>;

						amoor_d(): base(id_t::amoor_d) {}
						amoor_d(word_t word): base(id_t::amoor_d, word) {}
					};
				}

				//
				class lr_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					lr_d(): base(id_t::lr_d) {}
					lr_d(word_t word): base(id_t::lr_d, word) {}
				};

				//
				class sc_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					sc_d(): base(id_t::sc_d) {}
					sc_d(word_t word): base(id_t::sc_d, word) {}
				};

				//
				class amoswap_d: public basic<format::base::r>
				{
				public:
					using base = basic<format::base::r>;

					amoswap_d(): base(id_t::amoswap_d) {}
					amoswap_d(word_t word): base(id_t::amoswap_d, word) {}
				};
			}
		}
	}
}
