#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, sqrtX) {
    Solution s;
    auto ans = s.mySqrt(0);
    EXPECT_EQ(ans, 0);

    ans = s.mySqrt(2);
    EXPECT_EQ(ans, 1);

    ans = s.mySqrt(100);
    EXPECT_EQ(ans, 10);

    ans = s.mySqrt(8);
    EXPECT_EQ(ans, 2);

    ans = s.mySqrt(1);
    EXPECT_EQ(ans, 1);
}