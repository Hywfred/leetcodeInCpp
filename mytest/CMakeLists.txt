# add source files
aux_source_directory(. mytest_src)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(mytest ${mytest_src})
# add test
add_test(NAME mytest COMMAND mytest)

target_link_libraries(mytest daily "gtest" "gtest_main")