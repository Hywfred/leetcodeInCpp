#include "gtest/gtest.h"
#include "daily.h"

TEST(mytest, Coin) {
    Solution s;
    int ans = s.waysToChange(5);
    EXPECT_EQ(ans, 2);
    ans = s.waysToChange(10);
    EXPECT_EQ(ans, 4);
}