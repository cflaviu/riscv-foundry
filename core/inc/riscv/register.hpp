#pragma once
#ifndef PCH
    #include <cstdint>
    #include <iosfwd>
#endif

namespace riscv
{
    using out_stream = std::ostream;

    namespace register_
    {
        class base
        {
        public:
            virtual ~base() = default;
        };

		template <typename T>
		class r: public base
		{
		};

		using r16 = r<std::uint16_t>;
		using r32 = r<std::uint32_t>;
		using r64 = r<std::uint64_t>;

		class r128: public base
		{
		public:
		};

		namespace set
		{
			class base
			{
			public:
				virtual ~base() = default;
			};

			template <typename T, const std::uint8_t size>
			class r: public base
			{
			};

			template <const std::uint8_t size>
			using r16 = r<uint16_t, size>;

			template <const std::uint8_t size>
			using r32 = r<uint32_t, size>;

			template <const std::uint8_t size>
			using r64 = r<uint64_t, size>;
		}

		using id_t = std::uint8_t;

		out_stream& print_gpr_register(out_stream& out, id_t reg_no);
		out_stream& print_gpr_abi_register(out_stream& out, id_t reg_no);
		out_stream& print_fpr_register(out_stream& out, id_t reg_no);
		out_stream& print_fpr_abi_register(out_stream& out, id_t reg_no);
	}
}
