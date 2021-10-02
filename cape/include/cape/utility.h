#pragma once

#include "cape/type_traits.h"

namespace cape
{
	template <class T>
	constexpr cape::remove_reference_t<T>&& move(T&& t) noexcept
	{
		return static_cast<cape::remove_reference_t<T>&&>(t);
	}

	template <class T1, class T2>
	struct pair
	{
		using first_type  = T1;
		using second_type = T2;

		constexpr pair() noexcept = default;
		constexpr pair(const T1& x, const T2& y) noexcept : first(x), second(y) {}

		T1 first;
		T2 second;
	};
}
