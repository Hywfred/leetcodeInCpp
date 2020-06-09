#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, translate_num) {
    Solution s;
    auto ans = s.translateNum(122);
    EXPECT_EQ(ans, 3);

    ans = s.translateNum(12258);
    EXPECT_EQ(ans, 5);

    ans = s.translateNum(0);
    EXPECT_EQ(ans, 1);

    ans = s.translateNum(1);
    EXPECT_EQ(ans, 1);

    ans = s.translateNum(10);
    EXPECT_EQ(ans, 2);

    ans = s.translateNum(102);
    EXPECT_EQ(ans, 2);

    ans = s.translateNum(1025);
    EXPECT_EQ(ans, 4);
}