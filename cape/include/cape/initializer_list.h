#pragma once

/*
 * Why I use 'std::initializer_list'  insteadd implementing it myself is due to this answer: https://stackoverflow.com/a/18166383
 * The name is important because the standard says it is. The standard needs some way for you to be able to say, "this
 * constructor can be passed a braced-init-list containing a sequence of values of the type T". That way was given the
 * name "std::initializer_list".
 * You cannot make a class that has all of the language properties of initializer_list. You can make one that satisfies
 * the conditions of the type specified by section [initializer.list.syn] of the standard. But you'll notice that the
 * only constructor specified there is a default constructor. The only way to create an initializer_list with actual
 * elements relies on the compiler, not user-land code.
 * So you can't replicate everything about initializer_list. Just as you can't replicate std::type_info. The C++
 * standard library is not optional.
 */

#include <initializer_list>

namespace cape
{
	template <class T>
	using initializer_list = std::initializer_list<T>;
}

// my implamentation for initializer_list based on cpprefereence and implementation of MSVC
#if 0

namespace std
{
	template <class T>
	class initializer_list
	{
	public:
		using value_type      = T;
		using reference       = const T&;
		using const_reference = const T&;
		using size_type       = cape::size_t;
		using iterator        = const T*;
		using const_iterator  = const T*;

		constexpr initializer_list() noexcept : first(nullptr), last(nullptr) {}
		constexpr initializer_list(const T* first, const T* last) noexcept : first(first), last(last) {}

		constexpr cape::size_t size() const noexcept { return static_cast<cape::size_t>(last - first); }

		constexpr const T* begin() const noexcept { return first; }
		constexpr const T* end() const noexcept { return last; }

	private:
		const T* first;
		const T* last;
	};

	template <class T>
	constexpr const T* begin(initializer_list<T> list) noexcept { return list.begin(); }

	template <class T>
	constexpr const T* end(initializer_list<T> list) noexcept { return list.end(); }
}

#endif
