#pragma once

#include "cape/initializer_list.h"

namespace cape
{
	template <class T>
	constexpr const T& max(const T& a, const T& b) noexcept { return (a < b) ? b : a; }

	template <class T, class Compare>
	constexpr const T& max(const T& a, const T& b, Compare comp) noexcept { return comp(a, b) ? b : a; }

	template <class T>
	constexpr T max(std::initializer_list<T> ilist) noexcept
	{
		auto result = ilist.begin();
		for (auto it = ilist.begin() + 1; it != ilist.end(); it++)
			if (*result < *it)
				result = it;
		return *result;
	}

	template <class T, class Compare>
	constexpr T max(std::initializer_list<T> ilist, Compare comp) noexcept
	{
		auto result = ilist.begin();
		for (auto it = ilist.begin() + 1; it != ilist.end(); it++)
			if (comp(*result, *it))
				result = it;
		return *result;
	}


	template <class T>
	constexpr const T& min(const T& a, const T& b) noexcept { return (a < b) ? a : b; }

	template <class T, class Compare>
	constexpr const T& min(const T& a, const T& b, Compare comp) noexcept { return comp(a, b) ? a : b; }

	template <class T>
	constexpr T min(std::initializer_list<T> ilist) noexcept
	{
		auto result = ilist.begin();
		for (auto it = ilist.begin() + 1; it != ilist.end(); it++)
			if (*it < *result)
				result = it;
		return *result;
	}

	template <class T, class Compare>
	constexpr T min(std::initializer_list<T> ilist, Compare comp) noexcept
	{
		auto result = ilist.begin();
		for (auto it = ilist.begin() + 1; it != ilist.end(); it++)
			if (comp(*it, *result))
				result = it;
		return *result;
	}
}
