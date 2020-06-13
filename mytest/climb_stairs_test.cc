#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, climb_stairs) {
    Solution s;
    auto ans = s.climbStairs(0);
    EXPECT_EQ(ans, 0);

    ans = s.climbStairs(1);
    EXPECT_EQ(ans, 1);

    ans = s.climbStairs(2);
    EXPECT_EQ(ans, 2);

    ans = s.climbStairs(3);
    EXPECT_EQ(ans, 3);

    ans = s.climbStairs(4);
    EXPECT_EQ(ans, 5);
}