# add source files
aux_source_directory(. SRCS)

include_directories(${CMAKE_SOURCE_DIR}/includes)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(mytest ${SRCS})

# add test
add_test(NAME mytest COMMAND mytest)

target_link_libraries(mytest "gtest" "gtest_main")