#include "daily.h"
#include "gtest/gtest.h"

TEST(mytest, happy_number) {
    Solution s;
    auto ans = s.isHappy(19);
    EXPECT_TRUE(ans);
    ans = s.isHappy(456);
    EXPECT_FALSE(ans);

    ans = s.isHappy(95846572);
    EXPECT_FALSE(ans);
}