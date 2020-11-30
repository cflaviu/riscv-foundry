#pragma once
#ifndef PCH
	#include <riscv/basic_types.hpp>
	#include <optional>
	#include <tuple>
#endif

namespace riscv
{
	namespace instruction
	{
		enum class type: std::uint8_t
		{
			load,
			load_floating_point,
			fence,
			arithmetic_immediate,
			auipc,
			arithmetic_extended,
			store,
			store_extended,
			arithmetic_atomic,
			arithmetic,
			load_unsinged_immediate,
			arithmetic_w,
			floating_point_add,
			floating_point_subtract,
			floating_point_subtract_negated,
			floating_point_add_negated,
			floating_point_arithmetic,
			branch,
			jump_and_link_register,
			jump_and_link,
			extra,
		};

		std::optional<type> type_of(opcode_t item) noexcept;
		std::optional<type> type_of(word_t item) noexcept;
	}
}
