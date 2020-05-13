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

# level order
add_executable(level ${levelorder_src})
add_test( level level)
target_link_libraries(level daily "gtest" "gtest_main")

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