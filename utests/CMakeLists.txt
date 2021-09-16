add_executable(utests
	src/main.cpp
)

target_link_libraries(utests PRIVATE
	doctest
	cape
)

target_compile_options(utests PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	$<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>: /WX>
)
