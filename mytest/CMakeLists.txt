cmake_minimum_required(VERSION 3.10)

project(mytest)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(sum1_n sum1_n_test.cc)
target_link_libraries(sum1_n daily "gtest" "gtest_main")
add_test(NAME sum1_n COMMAND sum1_n)

# add_executable(kids_with_candies kids_with_candies_test.cc)
# target_link_libraries(kids_with_candies daily "gtest" "gtest_main")
# add_test(NAME kids_with_candies COMMAND kids_with_candies)

# add_executable(rob rob_test.cc)
# target_link_libraries(rob daily "gtest" "gtest_main")
# add_test(NAME rob COMMAND rob)

# add_executable(symmetric_tree symmetric_tree_test.cc)
# target_link_libraries(symmetric_tree daily "gtest" "gtest_main")
# add_test(NAME symmetric_tree COMMAND symmetric_tree)