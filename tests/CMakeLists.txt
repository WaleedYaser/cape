file(GLOB cape_tests src/*.cpp)
foreach(cape_test_cpp ${cape_tests})
	get_filename_component(cape_test_name ${cape_test_cpp} NAME_WE)
	# TODO: reguire cmake version 3.20
	# cmake_path(GET cape_test_cpp STEM cape_test_name)
	add_executable(${cape_test_name} ${cape_test_cpp})
	target_link_libraries(${cape_test_name} PRIVATE cape)
	add_test(NAME ${cape_test_name} COMMAND ${cape_test_name})
endforeach()