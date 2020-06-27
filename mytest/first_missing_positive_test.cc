#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, first_missing_positive) {
    Solution s;
    vector<int> input{1, 2, 0};
    auto ans = s.firstMissingPositive(input);
    int wanted = 3;
    EXPECT_EQ(ans, wanted) << wanted;

    input = {3, 4, -1, 1};
    ans = s.firstMissingPositive(input);
    wanted = 2;
    EXPECT_EQ(ans, wanted) << wanted;

    input = {7, 8, 9, 11, 12};
    ans = s.firstMissingPositive(input);
    wanted = 1;
    EXPECT_EQ(ans, wanted) << wanted;

    input = {1, 1};
    ans = s.firstMissingPositive(input);
    wanted = 2;
    EXPECT_EQ(ans, wanted) << wanted;
}