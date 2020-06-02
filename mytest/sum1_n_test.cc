#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, sum1_n) {
    Solution s;
    auto ans = s.sumNums(1);
    EXPECT_EQ(ans, 1);

    ans = s.sumNums(9);
    EXPECT_EQ(ans, 45);

    ans = s.sumNums(6);
    EXPECT_EQ(ans, 21);
}