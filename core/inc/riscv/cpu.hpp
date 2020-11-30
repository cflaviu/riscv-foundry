#pragma once
#ifndef PCH
	#include <riscv/basic_types.hpp>
#endif

namespace riscv
{
	namespace cpu
	{
		class base
		{
		public:
			virtual ~base() = default;
		};

		namespace scalar
		{
			class base: public cpu::base
			{
			public:
			};

			template <const std::uint8_t size>
			class sc1: public base
			{
			public:
//				using register_set = std::array<_Register, _Register_count>;
//				using internal_register_set = std::array<_Register, _Internal_register_count>;

//				const register_set& registers() const { return _registers; }
//				const internal_register_set& internal_registers() { return _internal_registers; }

//			protected:
//				register_set _registers;
//				internal_register_set _internal_registers;
			};
		}

		namespace superscalar
		{
			class base: public cpu::base
			{
			public:
			};

			class ssc1: public base
			{
			public:
			};
		}
	}
}
