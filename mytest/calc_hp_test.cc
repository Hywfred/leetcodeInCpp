#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, calc_hp) {
    Solution s;
    vector<vector<int>> input{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    auto ans = s.calculateMinimumHP(input);
    EXPECT_EQ(ans, 7);

    input = {};
    ans = s.calculateMinimumHP(input);
    EXPECT_EQ(ans, 1);

    input = {{-9}};
    ans = s.calculateMinimumHP(input);
    EXPECT_EQ(ans, 10);

    input = {{10}};
    ans = s.calculateMinimumHP(input);
    EXPECT_EQ(ans, 1);

    input = {{0, -5}, {0, 0}};
    ans = s.calculateMinimumHP(input);
    EXPECT_EQ(ans, 1);
}