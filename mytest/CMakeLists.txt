cmake_minimum_required(VERSION 3.10)

project(mytest)

link_directories(${CMAKE_SOURCE_DIR}/lib)

# add_executable(rob rob_test.cc)
# target_link_libraries(rob daily "gtest" "gtest_main")
# add_test(NAME rob COMMAND rob)

add_executable(symmetric_tree symmetric_tree_test.cc)
target_link_libraries(symmetric_tree daily "gtest" "gtest_main")
add_test(NAME symmetric_tree COMMAND symmetric_tree)