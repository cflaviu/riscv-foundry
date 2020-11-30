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
		enum class id_t: std::uint8_t;

		namespace identification
		{
			namespace arithmentic
			{
				std::optional<id_t> atomic(std::uint16_t id);
				std::optional<id_t> basic(std::uint16_t id);
				std::optional<id_t> extended(std::uint16_t id);
				std::optional<id_t> immediate(std::uint16_t id);
				std::optional<id_t> w(std::uint16_t id);
			}

			namespace floating_point
			{
				std::optional<id_t> add_negated(std::uint16_t id);
				std::optional<id_t> add(std::uint16_t id);
				std::optional<id_t> arithmetic(std::uint16_t id);
				std::optional<id_t> load(std::uint16_t id);
				std::optional<id_t> subtract_negated(std::uint16_t id);
				std::optional<id_t> subtract(std::uint16_t id);
			}

			std::optional<id_t> auipc(std::uint16_t id);
			std::optional<id_t> branch(std::uint16_t id);
			std::optional<id_t> extra(std::uint16_t id);
			std::optional<id_t> fence(std::uint16_t id);

			std::optional<id_t> jump_and_link_register(std::uint16_t id);
			std::optional<id_t> jump_and_link(std::uint16_t id);
			std::optional<id_t> load(std::uint16_t id);
			std::optional<id_t> load_unsinged_immediate(std::uint16_t id);
			std::optional<id_t> store_extended(std::uint16_t id);
			std::optional<id_t> store(std::uint16_t id);
		}
	}
}
