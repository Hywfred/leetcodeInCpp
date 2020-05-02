# add source files
# aux_source_directory(. mytest_src)

link_directories(${CMAKE_SOURCE_DIR}/lib)

# add_executable(mytest ${mytest_src})
# add test
# add_test(NAME mytest COMMAND mytest)

set(longest_sub_str LongestSubStr-test.cpp)

add_executable(lgstSubStr ${longest_sub_str})
add_test(lgstSubStr lgstSubStr)
target_link_libraries(lgstSubStr daily "gtest" "gtest_main")