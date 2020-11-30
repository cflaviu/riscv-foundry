#pragma once
#ifndef PCH
    #include <cstdint>
#endif

namespace riscv
{
    namespace unit
    {
        class base
        {
        public:
            virtual ~base() = default;
        };

		// arithmetic logic unit
		namespace alu
		{
			class base: public unit::base
			{
			public:
			};
		}

		// fixed-point execution unit
		namespace fxu
		{
			class base: public unit::base
			{
			public:
			};
		}

		// fixed-point execution unitfixed-point execution unit
		namespace fpu
		{
			enum class rounding_mode
			{
				rne,		// round to nearest, ties to even
				rtz,		// round towards zero
				rdn,		// round down
				rup,		// round up
				rmm,		// round to nearest, ties to max magnitude
				dyn = 7		// dynamic rounding mode
			};

			class base: public unit::base
			{
			public:
			};
		}

		// address generation unit
		namespace agu
		{
			class base: public unit::base
			{
			public:
			};
		}

		namespace branch_prediction
		{
			class base: public unit::base
			{
			public:
			};
		}

		// memory management unit
		namespace mmu
		{
			class base: public unit::base
			{
			public:
			};
		}

		// translation lookaside buffer
		namespace tlb
		{
			class base: public unit::base
			{
			public:
			};
		}

		// memory interface unit
		namespace miu
		{
			class base: public unit::base
			{
			public:
			};
		}

		// memory order buffer
		namespace mob
		{
			class base: public unit::base
			{
			public:
			};
		}

		namespace simd
		{
			class base: public unit::base
			{
			public:
			};

			// SIMD ALU
			class alu: public base
			{
			public:
			};

			// SIMD FPU
			class fpu: public base
			{
			public:
			};
		}

		namespace cache
		{
			class base: public unit::base
			{
			public:
			};

			namespace instruction
			{
				class base
				{
				public:
				};
			}

			namespace data
			{
				class base
				{
				public:
				};
			}

			namespace unified
			{
				class base
				{
				public:
				};
			}
		}

		namespace scheduler
		{
			class base: public unit::base
			{
			public:
			};
		}

		namespace decoder
		{
			class base: public unit::base
			{
			public:
			};
		}
	}
}
