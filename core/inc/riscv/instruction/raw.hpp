#pragma once
#ifndef PCH
    #include <riscv/instruction/field.hpp>
    #include <utility>
    #include <iosfwd>
#endif

namespace riscv
{
    using out_stream = std::ostream;

    namespace instruction
    {
        template <typename _Bitfields>
        class raw
        {
        public:
            using bitfields_t = _Bitfields;

        protected:
            union data_t
            {
                word_t	word;
                bitfields_t	fields;

				data_t(word_t item) noexcept: word(item) {}
				explicit data_t(const bitfields_t& item) noexcept: fields(item) {}

				template <typename ...Args>
				data_t(opcode_t opcode, Args... args) noexcept: fields(opcode, args...) {}

				bool operator == (const data_t& item) const noexcept { return word == item.word; }
				bool operator != (const data_t& item) const noexcept { return word == item.word; }

				void operator = (word_t item) noexcept { word = item; }
				void operator = (const bitfields_t& item) noexcept { fields = item; }

				void operator = (const data_t& item) noexcept
				{
					if (this != &item)
					{
						word = item.word;
					}
				}
			};

			data_t data_;

		public:
			raw(word_t item = 0) noexcept: data_(item) {}
			explicit raw(const bitfields_t& item) noexcept: data_(item) {}

			template <typename ...Args>
			raw(field::opcode opc, Args... args) noexcept: data_(static_cast<opcode_t>(opc), args...) {}

			opcode_t opcode() const noexcept { return data_.fields.opcode; }
			word_t word() const noexcept { return data_.word; }

			operator word_t() const noexcept { return data_.word; }

			const bitfields_t& operator () () const noexcept { return data_.fields; }
			bitfields_t& operator () () noexcept { return data_.fields; }

			bool operator == (const data_t& item) const noexcept { return data_ == item.data_; }
			bool operator != (const data_t& item) const noexcept { return data_ != item.data_; }

			void operator = (word_t item) noexcept { data_ = item; }
			void operator = (const bitfields_t& item) noexcept { data_ = item; }
			void operator = (const raw& item) noexcept { data_ = item.data_; }

			out_stream& print(out_stream& out) const
			{
				return data_.fields.print(out);
			}
		};
	}
}
