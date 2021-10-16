#pragma once

#include "cape/types.h"
#include "cape/type_traits.h"

namespace cape
{
	template <class T>
	constexpr cape::remove_reference_t<T>&& move(T&& t) noexcept
	{
		return static_cast<cape::remove_reference_t<T>&&>(t);
	}

	// forward lvalues as either lvalues or as rvalues depending on T
	template <class T>
	constexpr T&& forward(cape::remove_reference_t<T>& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	// forward rvalues as rvalues and prohibits forwarding of rvalues as lvalues
	template <class T>
	constexpr T&& forward(cape::remove_reference_t<T>&& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	template <class T>
	requires is_move_constructible_v<T> && is_move_assignable_v<T>
	constexpr void swap(T& a, T& b) noexcept (is_nothrow_move_constructible_v<T> && is_nothrow_move_assignable_v<T>)
	{
		T tmp(move(a));
		a = move(b);
		b = move(tmp);
	}

	template <class T, size_t N>
	requires is_swappable_v<T>
	constexpr void swap(T (&a)[N], T(&b)[N]) noexcept (is_nothrow_swappable_v<T>)
	{
		for (size_t i = 0; i < N; ++i)
			swap(a[i], b[i]);
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
