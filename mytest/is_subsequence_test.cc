#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_subsequence) {
    Solution s;
    auto ans = s.isSubsequence("", "");
    EXPECT_TRUE(ans);

    ans = s.isSubsequence("", "abc");
    EXPECT_TRUE(ans);

    ans = s.isSubsequence("abc", "");
    EXPECT_FALSE(ans);

    ans = s.isSubsequence("abc", "ahbgdc");
    EXPECT_TRUE(ans);

    ans = s.isSubsequence("axc", "ahbgdc");
    EXPECT_FALSE(ans);
}