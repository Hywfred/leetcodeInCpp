#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, maximum_sub_arr) {
    Solution s;
    vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto ans = s.maxSubArray(input);
    EXPECT_EQ(ans, 6);

    input = {-2, 1, -3, 4, -1, 2};
    ans = s.maxSubArray(input);
    EXPECT_EQ(ans, 5);

    input = {};
    ans = s.maxSubArray(input);
    EXPECT_EQ(ans, 0);

    input = {-2};
    ans = s.maxSubArray(input);
    EXPECT_EQ(ans, -2);
}