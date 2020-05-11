#include "daily.h"
#include "gtest/gtest.h"
#include <cmath>

using namespace std;

TEST(mytest, power_xn) {
    Solution s;
    auto ans = s.myPow(2.00000, 10);
    EXPECT_TRUE(ans == 1024.00000) << "expect: " << 1024 << " actual: " << ans << endl;

    ans = s.myPow(2.00000, -2);
    EXPECT_TRUE(ans == 0.25000) << "expect: " << 0.25000 << " actual: " << ans << endl;

    ans = s.myPow(2.00000, 1);
    EXPECT_TRUE(ans == 2.00000) << "expect: " << 2.00000 << " actual: " << ans << endl;

    ans = s.myPow(-9, 0);
    EXPECT_EQ(ans, 1) << "expect: " << 1 << " actual: " << ans << endl;
}