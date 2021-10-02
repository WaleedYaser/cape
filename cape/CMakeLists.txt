set(HEADER_FILES
	# include/cape/Exports.h
	# include/cape/defines.h
	# include/cape/types.h
	# include/cape/initializer_list.h
	# include/cape/algorithm.h
)

set(SOURCE_FILES
)

add_library(cape INTERFACE)
# target_sources(cape PRIVATE ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(cape INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# include(GenerateExportHeader)
# generate_export_header(cape
# 	EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/cape/Exports.h
# )

target_compile_options(cape INTERFACE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	$<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>: /WX>
)
