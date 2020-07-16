cmake_minimum_required(VERSION 3.10)

project(mytest)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(num_tree num_tree_test.cc)
target_link_libraries(num_tree daily weekly "gtest" "gtest_main")
add_test(NAME num_tree COMMAND num_tree)

# add_executable(min_total min_total_test.cc)
# target_link_libraries(min_total daily weekly "gtest" "gtest_main")
# add_test(NAME min_total COMMAND min_total)


# add_executable(calc_hp calc_hp_test.cc)
# target_link_libraries(calc_hp daily weekly "gtest" "gtest_main")
# add_test(NAME calc_hp COMMAND calc_hp)

# add_executable(count_smaller count_smaller_test.cc)
# target_link_libraries(count_smaller daily weekly "gtest" "gtest_main")
# add_test(NAME count_smaller COMMAND count_smaller)

# add_executable(max_profit max_profit_test.cc)
# target_link_libraries(max_profit daily weekly "gtest" "gtest_main")
# add_test(NAME max_profit COMMAND max_profit)

# add_executable(sap sap_test.cc)
# target_link_libraries(sap daily weekly "gtest" "gtest_main")
# add_test(NAME sap COMMAND sap)

# add_executable(respace respace_test.cc)
# target_link_libraries(respace daily weekly "gtest" "gtest_main")
# add_test(NAME respace COMMAND respace)

# add_executable(diving_board diving_board_test.cc)
# target_link_libraries(diving_board daily weekly "gtest" "gtest_main")
# add_test(NAME diving_board COMMAND diving_board)

# add_executable(path_sum path_sum_test.cc)
# target_link_libraries(path_sum daily weekly "gtest" "gtest_main")
# add_test(NAME path_sum COMMAND path_sum)

# add_executable(treenode_test treenode_test.cc)
# target_link_libraries(treenode_test daily weekly "gtest" "gtest_main")
# add_test(NAME treenode_test COMMAND treenode_test)

# add_executable(unique_path unique_path_test.cc)
# target_link_libraries(unique_path daily weekly "gtest" "gtest_main")
# add_test(NAME unique_path COMMAND unique_path)

# add_executable(is_match_ii is_match_ii_test.cc)
# target_link_libraries(is_match_ii daily weekly "gtest" "gtest_main")
# add_test(NAME is_match_ii COMMAND is_match_ii)

# add_executable(last_moment get_last_moment_test.cc)
# target_link_libraries(last_moment daily weekly "gtest" "gtest_main")
# add_test(NAME last_moment COMMAND last_moment)

# add_executable(arithmetic can_make_arithmetic_progression_test.cc)
# target_link_libraries(arithmetic daily weekly "gtest" "gtest_main")
# add_test(NAME arithmetic COMMAND arithmetic)

# add_executable(sorted_array_toBST sorted_array_toBST_test.cc)
# target_link_libraries(sorted_array_toBST daily "gtest" "gtest_main")
# add_test(NAME sorted_array_toBST COMMAND sorted_array_toBST)

# add_executable(kth_smallest kth_smallest_test.cc)
# target_link_libraries(kth_smallest daily "gtest" "gtest_main")
# add_test(NAME kth_smallest COMMAND kth_smallest)

# add_executable(find_len find_length_test.cc)
# target_link_libraries(find_len daily "gtest" "gtest_main")
# add_test(NAME find_len COMMAND find_len)

# add_executable(kth_largest kth_largest_test.cc)
# target_link_libraries(kth_largest daily "gtest" "gtest_main")
# add_test(NAME kth_largest COMMAND kth_largest)

# add_executable(min_subarray_len min_subarray_len_test.cc)
# target_link_libraries(min_subarray_len daily "gtest" "gtest_main")
# add_test(NAME min_subarray_len COMMAND min_subarray_len)

# add_executable(first_missing_positive first_missing_positive_test.cc)
# target_link_libraries(first_missing_positive daily "gtest" "gtest_main")
# add_test(NAME first_missing_positive COMMAND first_missing_positive)

# add_executable(remove_duplicate remove_duplicate_node_test.cc)
# target_link_libraries(remove_duplicate daily "gtest" "gtest_main")
# add_test(NAME remove_duplicate COMMAND remove_duplicate)

# add_executable(word_break word_break_test.cc)
# target_link_libraries(word_break daily "gtest" "gtest_main")
# add_test(NAME word_break COMMAND word_break)

# add_executable(three_sum_closest three_sum_closest_test.cc)
# target_link_libraries(three_sum_closest daily "gtest" "gtest_main")
# add_test(NAME three_sum_closest COMMAND three_sum_closest)

# add_executable(add_binary add_binary_test.cc)
# target_link_libraries(add_binary daily "gtest" "gtest_main")
# add_test(NAME add_binary COMMAND add_binary)

# add_executable(pattern_matching pattern_matching_test.cc)
# target_link_libraries(pattern_matching daily "gtest" "gtest_main")
# add_test(NAME pattern_matching COMMAND pattern_matching)

# add_executable(max_path max_path_test.cc)
# target_link_libraries(max_path daily weekly "gtest" "gtest_main")
# add_test(NAME max_path COMMAND max_path)

# add_executable(file_uni filenames_unique_test.cc)
# target_link_libraries(file_uni daily weekly "gtest" "gtest_main")
# add_test(NAME file_uni COMMAND file_uni)

# add_executable(is_match is_match_test.cc)
# target_link_libraries(is_match daily "gtest" "gtest_main")
# add_test(NAME is_match COMMAND is_match)

# add_executable(is_palindrome is_palindrome_test.cc)
# target_link_libraries(is_palindrome daily "gtest" "gtest_main")
# add_test(NAME is_palindrome COMMAND is_palindrome)

# add_executable(recover_from_preorder recover_from_preorder_test.cc)
# target_link_libraries(recover_from_preorder daily "gtest" "gtest_main")
# add_test(NAME recover_from_preorder COMMAND recover_from_preorder)

# add_executable(treenode_test treenode_test.cc)
# target_link_libraries(treenode_test daily "gtest" "gtest_main")
# add_test(NAME treenode_test COMMAND treenode_test)


# add_executable(max_score max_score_sightseeing_pair_test.cc)
# target_link_libraries(max_score daily "gtest" "gtest_main")
# add_test(NAME max_score COMMAND max_score)

# add_executable(serialize_deserialize_binarytree serialize_deserialize_binarytree_test.cc)
# target_link_libraries(serialize_deserialize_binarytree daily "gtest" "gtest_main")
# add_test(NAME serialize_deserialize_binarytree COMMAND serialize_deserialize_binarytree)

# add_executable(longest_common_prefix longest_common_prefix_test.cc)
# target_link_libraries(longest_common_prefix daily "gtest" "gtest_main")
# add_test(NAME longest_common_prefix COMMAND longest_common_prefix)

# add_executable(find_best_value find_best_value_test.cc)
# target_link_libraries(find_best_value daily "gtest" "gtest_main")
# add_test(NAME find_best_value COMMAND find_best_value)

# add_executable(climb_stairs climb_stairs_test.cc)
# target_link_libraries(climb_stairs daily "gtest" "gtest_main")
# add_test(NAME climb_stairs COMMAND climb_stairs)

# add_executable(three_sum three_sum_test.cc)
# target_link_libraries(three_sum daily "gtest" "gtest_main")
# add_test(NAME three_sum COMMAND three_sum)

# add_executable(daily_temperature daily_temperature_test.cc)
# target_link_libraries(daily_temperature daily "gtest" "gtest_main")
# add_test(NAME daily_temperature COMMAND daily_temperature)

# add_executable(palindrome_num palindrome_num_test.cc)
# target_link_libraries(palindrome_num daily "gtest" "gtest_main")
# add_test(NAME palindrome_num COMMAND translate_num)

# add_executable(translate_num translate_num_test.cc)
# target_link_libraries(translate_num daily "gtest" "gtest_main")
# add_test(NAME translate_num COMMAND translate_num)

# add_executable(equations_possible equations_possible_test.cc)
# target_link_libraries(equations_possible daily "gtest" "gtest_main")
# add_test(NAME equations_possible COMMAND equations_possible)

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