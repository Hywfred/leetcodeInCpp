#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, jump_game) {
    Solution s;
    vector<int> input{2, 3, 1, 1, 4};
    auto ans = s.jump(input);
    EXPECT_EQ(ans, 2);

    input = {2, 2, 3, 1, 1, 4};
    ans = s.jump(input);
    EXPECT_EQ(ans, 2);

    input = {1, 2, 3, 1, 1, 4};
    ans = s.jump(input);
    EXPECT_EQ(ans, 3);

    input = {0};
    ans = s.jump(input);
    EXPECT_EQ(ans, 0);

    input = {5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5};
    ans = s.jump(input);
    EXPECT_EQ(ans, 5);
}