cmake_minimum_required(VERSION 3.10)

project(mytest)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(equations_possible equations_possible_test.cc)
target_link_libraries(equations_possible daily "gtest" "gtest_main")
add_test(NAME equations_possible COMMAND equations_possible)

# add_executable(find_ladders find_ladders_test.cc)
# target_link_libraries(find_ladders daily "gtest" "gtest_main")
# add_test(NAME find_ladders COMMAND find_ladders)

# add_executable(longest_consecutive longest_consecutive_test.cc)
# target_link_libraries(longest_consecutive daily "gtest" "gtest_main")
# add_test(NAME longest_consecutive COMMAND longest_consecutive)

# add_executable(spiral_order spiral_order_test.cc)
# target_link_libraries(spiral_order daily "gtest" "gtest_main")
# add_test(NAME spiral_order COMMAND spiral_order)

# add_executable(product_except_self product_except_self_test.cc)
# target_link_libraries(product_except_self daily "gtest" "gtest_main")
# add_test(NAME product_except_self COMMAND product_except_self)

# add_executable(new_21 new_21_test.cc)
# target_link_libraries(new_21 daily "gtest" "gtest_main")
# add_test(NAME new_21 COMMAND new_21)

# add_executable(sum1_n sum1_n_test.cc)
# target_link_libraries(sum1_n daily "gtest" "gtest_main")
# add_test(NAME sum1_n COMMAND sum1_n)

# add_executable(kids_with_candies kids_with_candies_test.cc)
# target_link_libraries(kids_with_candies daily "gtest" "gtest_main")
# add_test(NAME kids_with_candies COMMAND kids_with_candies)

# add_executable(rob rob_test.cc)
# target_link_libraries(rob daily "gtest" "gtest_main")
# add_test(NAME rob COMMAND rob)

# add_executable(symmetric_tree symmetric_tree_test.cc)
# target_link_libraries(symmetric_tree daily "gtest" "gtest_main")
# add_test(NAME symmetric_tree COMMAND symmetric_tree)