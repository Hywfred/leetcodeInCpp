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