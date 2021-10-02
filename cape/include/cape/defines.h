#pragma once

// Compiler version are taken from: https://github.com/cxxstuff/cxx_detect

#define CAPE_CLANG 0
#define CAPE_GCC   0
#define CAPE_MSVC  0

#define CAPE_MAKE_VER(MAJOR, MINOR, PATCH) ((MAJOR) * 10000000 + (MINOR) * 100000 + (PATCH))

#if defined(_MSC_VER) && defined(_MSC_FULL_VER)
	#undef CAPE_MSVC
	#if _MSC_VER == _MSC_FULL_VER / 10000
		#define CAPE_MSVC CAPE_MAKE_VER(_MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 10000)
	#else
		#define CAPE_MSVC CAPE_MAKE_VER(_MSC_VER / 100, (_MSC_FULL_VER / 100000) % 100, _MSC_FULL_VER % 100000)
	#endif
#elif defined(__GNUC__) && defined(__GNUC_MINOR__) && defined(__GNUC_PATCHLEVEL__)
	#undef CAPE_GCC
	#define CAPE_GCC CAPE_MAKE_VER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#elif defined(__clang__) && defined(__clang_minor__)
	#undef CAPE_CLANG
	#define CAPE_CLANG CAPE_MAKE_VER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#else
	#error "[cape/defines.h] Unable to detect C/C++ compiler."
#endif
