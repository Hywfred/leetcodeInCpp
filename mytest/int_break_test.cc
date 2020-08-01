#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, int_break) {
    Solution s;
    auto ans = s.integerBreak(2);
    EXPECT_EQ(ans, 1);

    ans = s.integerBreak(3);
    EXPECT_EQ(ans, 2);

    ans = s.integerBreak(4);
    EXPECT_EQ(ans, 4);

    ans = s.integerBreak(5);
    EXPECT_EQ(ans, 6);

    ans = s.integerBreak(10);
    EXPECT_EQ(ans, 36);
}