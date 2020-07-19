#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, max_coin) {
    Solution s;
    vector<int> input{3, 1, 5, 8};
    auto ans = s.maxCoins(input);
    EXPECT_EQ(ans, 167);

    input = {};
    ans = s.maxCoins(input);
    EXPECT_EQ(ans, 0);

    input = {3};
    ans = s.maxCoins(input);
    EXPECT_EQ(ans, 3);

    input = {3, 5};
    ans = s.maxCoins(input);
    EXPECT_EQ(ans, 20);

    input = {7, 9, 8, 0, 7, 1, 3, 5, 5, 2, 3};
    ans = s.maxCoins(input);
    EXPECT_EQ(ans, 20);
}