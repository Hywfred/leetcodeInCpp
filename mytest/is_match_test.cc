#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_match) {
    Solution s;
    auto ans = s.isMatch("", "");
    EXPECT_TRUE(ans) << "";

    ans = s.isMatch("", "a");
    EXPECT_FALSE(ans) << ""
                      << "--a";

    ans = s.isMatch("a", "");
    EXPECT_FALSE(ans) << "a";

    ans = s.isMatch("aa", "a");
    EXPECT_FALSE(ans) << "aa";

    ans = s.isMatch("aa", "a*");
    EXPECT_TRUE(ans) << "aa"
                     << "--a*";

    ans = s.isMatch("ab", ".*");
    EXPECT_TRUE(ans) << "ab";

    ans = s.isMatch("aab", "c*a*b");
    EXPECT_TRUE(ans) << "aab";

    ans = s.isMatch("mississippi", "mis*is*p*.");
    EXPECT_FALSE(ans) << "mississippi";

    ans = s.isMatch("aaa", "a*a");
    EXPECT_TRUE(ans) << "aaa";

    ans = s.isMatch("ab", "a*ab");
    EXPECT_TRUE(ans) << "ab";

    ans = s.isMatch("aab", "a*b");
    EXPECT_TRUE(ans) << "aab"
                     << "--a*b";

    ans = s.isMatch("aa", "aacd");
    EXPECT_FALSE(ans) << "aa"
                      << "--aacd";

    ans = s.isMatch("ab", ".*c");
    EXPECT_FALSE(ans) << "ab"
                      << "--.*c";

    ans = s.isMatch("", ".*");
    EXPECT_TRUE(ans) << ""
                     << "--.*";
}