#pragma once

namespace cape
{
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
