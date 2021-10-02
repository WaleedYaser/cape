set(HEADER_FILES
	include/cape/Exports.h
	include/cape/types.h
	include/cape/initializer_list.h
	include/cape/algorithm.h
)

set(SOURCE_FILES
	src/cape/test.cpp
)

add_library(cape)
target_sources(cape PRIVATE ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(cape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(GenerateExportHeader)
generate_export_header(cape
	EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/cape/Exports.h
)

target_compile_options(cape PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	$<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>: /WX>
)
