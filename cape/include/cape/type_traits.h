#pragma once

namespace cape
{
	template <class T> struct remove_reference      { using type = T; };
	template <class T> struct remove_reference<T&>  { using type = T; };
	template <class T> struct remove_reference<T&&> { using type = T; };
	template <class T> using remove_reference_t = typename remove_reference<T>::type;

	// TODO: write implementation
	template <class T> struct is_move_constructible { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_move_constructible_v = is_move_constructible<T>::value;

	// TODO: write implementation
	template <class T> struct is_move_assignable { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_move_assignable_v = is_move_assignable<T>::value;

	// TODO: write implementation
	template <class T> struct is_nothrow_move_constructible { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<T>::value;

	// TODO: write implementation
	template <class T> struct is_nothrow_move_assignable { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<T>::value;

	// TODO: write implementation
	template <class T> struct is_nothrow_swappable { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<T>::value;

	// TODO: write implementation
	template <class T> struct is_swappable { static constexpr bool value = true; };
	template <class T> inline constexpr bool is_swappable_v = is_swappable<T>::value;
}
