#pragma once
#ifndef PCH
	#include <cstdint>
	#include <type_traits>
#endif

namespace riscv
{
	using byte = std::uint8_t;

	struct context_t
	{};

    namespace instruction
    {
        using opcode_t = std::uint8_t;

        using word_t = std::uint32_t;
        using unsigned_word_t = std::uint32_t;
        using signed_word_t = std::int32_t;

        using half_word_t = std::uint16_t;
        using signed_half_word_t = std::int16_t;
        using unsigned_half_word_t = std::uint16_t;
    }

    // adapted from stackoverflow
    inline auto operator "" _KiB (unsigned long long value) noexcept { return value * 1024u; }
    inline auto operator "" _MiB (unsigned long long value) noexcept { return value * 1024u * 1024u; }

    // adapted from stackoverflow
    template <typename T>
    constexpr auto operator + (T e) noexcept //-> std::enable_if_t<std::is_enum<T>::value, std::underlying_type_t<T>>
    {
        return static_cast<std::underlying_type_t<T>>(e);
    }
}
