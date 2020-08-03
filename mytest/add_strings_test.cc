#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, add_strings) {
    Solution s;
    auto ans = s.addStrings("", "123");
    EXPECT_EQ(ans, "123");

    ans = s.addStrings("123", "");
    EXPECT_EQ(ans, "123");

    ans = s.addStrings("12345", "67");
    EXPECT_EQ(ans, "12412");

    ans = s.addStrings("999", "1");
    EXPECT_EQ(ans, "1000");

    ans = s.addStrings("99873", "215");
    EXPECT_EQ(ans, "100088");
}