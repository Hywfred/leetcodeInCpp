#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, rob_test) {
    Solution s;
    vector<int> input{1, 2, 3, 1};
    auto ans = s.rob(input);
    EXPECT_EQ(ans, 4);

    input = {2, 7, 9, 3, 1};
    ans = s.rob(input);
    EXPECT_EQ(ans, 12);

    input = {};
    ans = s.rob(input);
    EXPECT_EQ(ans, 0);

    input = {2, 8, 9, 4, 7, 5, 0, 6, 2, 0, 5, 8, 9, 4, 5, 6, 4};
    ans = s.rob(input);
    EXPECT_EQ(ans, 47);

    input = {0};
    ans = s.rob(input);
    EXPECT_EQ(ans, 0);
}