#pragma once
#ifndef PCH
	#include <riscv/instruction/type.hpp>
	#include <riscv/instruction/item.hpp>
	#include <vector>
	#include <memory>
#endif

namespace riscv
{
	namespace dissassembler
	{
		class alpha1
		{
		public:
			using word_t = instruction::word_t;
			using input_t = word_t;
			using instruction_array = std::vector<std::unique_ptr<instruction::item>>;

			alpha1();

			const instruction_array& instructions() const noexcept { return instructions_; }

			void operator () (const input_t* binary_code_begin, const input_t* binary_code_end);

		protected:
			void decode_load(word_t word);
			void decode_fence(word_t word);
			void decode_arithmetic_immediate(word_t word);
			void decode_auipc(word_t word);
			void decode_arithmetic_extended(word_t word);
			void decode_store(word_t word);
			void decode_store_extended(word_t word);
			void decode_arithmetic_atomic(word_t word);
			void decode_arithmetic(word_t word);
			void decode_load_unsinged_immediate(word_t word);
			void decode_arithmetic_w(word_t word);
			void decode_floating_point_add(word_t word);
			void decode_floating_point_load(word_t word);
			void decode_floating_point_subtract(word_t word);
			void decode_floating_point_subtract_negated(word_t word);
			void decode_floating_point_add_negated(word_t word);
			void decode_floating_point_arithmetic(word_t word);
			void decode_branch(word_t word);
			void decode_jump_and_link_register(word_t word);
			void decode_jump_and_link(word_t word);
			void decode_extra(word_t word);

			template <typename T>
			void add(word_t word)
			{
				instructions_.emplace_back(std::make_unique<T>(word));
			}

			using decode_method = void (alpha1::*)(word_t word);
			using decode_method_array = std::array<decode_method, 21>;

			instruction_array instructions_;
			decode_method_array decode_methods_;
		};
	}
}
