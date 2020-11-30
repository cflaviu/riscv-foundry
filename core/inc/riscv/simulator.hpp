#pragma once
#ifndef PCH
	#include <cstdint>
#endif

namespace riscv
{
	namespace simulator
	{
		class base
		{
		public:
			virtual ~base() = default;
		};

		namespace scalar
		{
			template <typename _Cpu, const std::uint8_t _Cpu_count>
			class t1: public base
			{
			};

			template <const std::uint8_t size>
			using s1 = t1<cpu::scalar::s1<32>, size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
		}

		namespace superscalar
		{
			template <typename _Cpu, const std::uint8_t _Cpu_count>
			class t1: public base
			{
			};

			template <const std::uint8_t _Size>
			using s1 = t1<cpu::superscalar::s1, _Size>;

			typedef s1<1> single_core1;
			typedef s1<2> dual_core1;
			typedef s1<4> quad_core1;
			typedef s1<8> octa_core1;
		}
	}
}
