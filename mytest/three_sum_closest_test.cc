#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, three_sum_closest) {
    Solution s;
    vector<int> input{-1, 2, 1, -4};
    auto ans = s.threeSumClosest(input, 1);
    EXPECT_EQ(ans, 2);

    ans = s.threeSumClosest(input, 10);
    EXPECT_EQ(ans, 2);

    ans = s.threeSumClosest(input, -4);
    EXPECT_EQ(ans, -4);

    ans = s.threeSumClosest(input, -10);
    EXPECT_EQ(ans, -4);

    ans = s.threeSumClosest(input, 0);
    EXPECT_EQ(ans, -1);

    input = {-5, -1, 8, 19, 3, 35, -10, 16};
    ans = s.threeSumClosest(input, 10);
    EXPECT_EQ(ans, 10);

    input = {1, 1, 1, 1};
    ans = s.threeSumClosest(input, -100);
    EXPECT_EQ(ans, 3);
}