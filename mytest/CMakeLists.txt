cmake_minimum_required(VERSION 3.10)

project(mytest)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(rob rob_test.cc)
target_link_libraries(rob daily "gtest" "gtest_main")
add_test(NAME rob COMMAND rob)