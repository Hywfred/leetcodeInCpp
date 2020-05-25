# add source files
# aux_source_directory(. mytest_src)

link_directories(${CMAKE_SOURCE_DIR}/lib)

# add_executable(mytest ${mytest_src})
# add test
# add_test(NAME mytest COMMAND mytest)

set(longest_sub_str LongestSubStr-test.cpp)
set(max_sub_arr MaximumSubArr-test.cpp)
set(jump_game_src JumpGameII-test.cpp)
set(validbst_src ValidBst-test.cpp)
set(mincosts_src MinCost4Tickets-test.cpp)
set(subtree_src Subtree-test.cpp)
set(maxSquare_src MaximalSquare-test.cpp)
set(sqrtx_src SqrtX-test.cpp)
set(power_src PowerXN-test.cpp)
set(minstack_src MinStack-test.cpp)
set(levelorder_src LevelOrder-test.cpp)
set(single_number_src SingleNumberII-test.cpp)
set(subarr_sum_k_src SubarrSumk-test.cpp)
set(reverse_k_src Reversek-test.cpp)
set(course_schedule_ii_src CourseScheduleII-test.cpp)
set(max_product_src MaxProduct-test.cpp)
set(valid_palindrome_ii_src ValidPalindromeII-test.cpp)
set(vowels_src Vowels-test.cpp)
set(longest_palindrome_src LongestPalindrome-test.cpp)
set(construct_binarytree_i_src construct_binarytree_i_test.cc)
set(minimum_window_substring_src minimum_window_substring_test.cc)
set(lru_cache_src lru_cache_test.cc)

# construct binary tree from preorder and inorder traversal
add_executable(lru_cache ${lru_cache_src})
add_test( lru_cache lru_cache)
target_link_libraries(lru_cache daily "gtest" "gtest_main")

# construct binary tree from preorder and inorder traversal
add_executable(minimum_window_substring ${minimum_window_substring_src})
add_test( minimum_window_substring minimum_window_substring)
target_link_libraries(minimum_window_substring daily "gtest" "gtest_main")

# construct binary tree from preorder and inorder traversal
add_executable(construct_binarytree_i ${construct_binarytree_i_src})
add_test( construct_binarytree_i construct_binarytree_i)
target_link_libraries(construct_binarytree_i daily "gtest" "gtest_main")

# find longest substring of s ion which vowels' count is even
add_executable(longest_palindrome ${longest_palindrome_src})
add_test( longest_palindrome longest_palindrome)
target_link_libraries(longest_palindrome daily "gtest" "gtest_main")

# find longest substring of s ion which vowels' count is even
add_executable(vowels ${vowels_src})
add_test( vowels vowels)
target_link_libraries(vowels daily "gtest" "gtest_main")

# valid palindrome II
add_executable(valid_palindrome_ii ${valid_palindrome_ii_src})
add_test( valid_palindrome_ii valid_palindrome_ii)
target_link_libraries(valid_palindrome_ii daily "gtest" "gtest_main")

# max product
add_executable(max_product ${max_product_src})
add_test( max_product max_product)
target_link_libraries(max_product daily "gtest" "gtest_main")

# course schedule ii
add_executable(course_schedule_ii ${course_schedule_ii_src})
add_test( course_schedule_ii course_schedule_ii)
target_link_libraries(course_schedule_ii daily "gtest" "gtest_main")

# reverse k group
add_executable(reverseK ${reverse_k_src})
add_test( reverseK reverseK)
target_link_libraries(reverseK daily "gtest" "gtest_main")

# subarray sum = k
add_executable(subarr_sum_k ${subarr_sum_k_src})
add_test( subarr_sum_k subarr_sum_k)
target_link_libraries(subarr_sum_k daily "gtest" "gtest_main")

# single_number
add_executable(single_number ${single_number_src})
add_test( single_number single_number)
target_link_libraries(single_number daily "gtest" "gtest_main")

# min stack
add_executable(minstack ${minstack_src})
add_test( minstack minstack)
target_link_libraries(minstack daily "gtest" "gtest_main")

# power(x, n)
add_executable(power ${power_src})
add_test( power power)
target_link_libraries(power daily "gtest" "gtest_main")

# 最长不重复子串
add_executable(lgstSubStr ${longest_sub_str})
add_test(lgstSubStr lgstSubStr)
target_link_libraries(lgstSubStr daily "gtest" "gtest_main")
# 最大子序和
add_executable(maximumSubArr ${max_sub_arr})
add_test(maximumSubArr maximumSubArr)
target_link_libraries(maximumSubArr daily "gtest" "gtest_main")
# 跳跃游戏II
add_executable(jumpgame ${jump_game_src})
add_test(jumpgame jumpgame)
target_link_libraries(jumpgame daily "gtest" "gtest_main")

# 验证二叉搜索树
add_executable(validbst ${validbst_src})
add_test(validbst validbst)
target_link_libraries(validbst daily "gtest" "gtest_main")

# 最低票价
add_executable(mincosts ${mincosts_src})
add_test(mincosts mincosts)
target_link_libraries(mincosts daily "gtest" "gtest_main")


# 另一棵树的子树
add_executable(subtree ${subtree_src})
add_test(subtree subtree)
target_link_libraries(subtree daily "gtest" "gtest_main")

# 最大的正方形
add_executable(maxSquare ${maxSquare_src})
add_test(maxSquare maxSquare)
target_link_libraries(maxSquare daily "gtest" "gtest_main")

# x 的平方根
add_executable(sqrtX ${sqrtx_src})
add_test( sqrtX sqrtX)
target_link_libraries(sqrtX daily "gtest" "gtest_main")