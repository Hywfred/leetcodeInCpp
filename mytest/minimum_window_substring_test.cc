#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, minimum_window_substring) {
    Solution s;
    auto ans = s.minWindow("ADOBECODEBANC", "ABC");
    EXPECT_EQ(ans, "BANC");

    ans = s.minWindow("", "ABC");
    EXPECT_EQ(ans, "");

    ans = s.minWindow("ADOBECODEBANC", "");
    EXPECT_EQ(ans, "");

    ans = s.minWindow("a", "a");
    EXPECT_EQ(ans, "a");

    ans = s.minWindow("a", "aa");
    EXPECT_EQ(ans, "");
}