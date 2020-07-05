#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_match_ii) {
    Solution s;
    auto ans = s.isMatchII("", "");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("ab", "");
    EXPECT_FALSE(ans);

    ans = s.isMatchII("", "abc");
    EXPECT_FALSE(ans);

    ans = s.isMatchII("ab", "ab****");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("abc", "*");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("", "*");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("adceb", "*a*b");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("acdcb", "a*c?b");
    EXPECT_FALSE(ans);

    ans = s.isMatchII("adceb", "a?*eb");
    EXPECT_TRUE(ans);

    ans = s.isMatchII("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
    EXPECT_FALSE(ans);

    ans = s.isMatchII(
        "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
        "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*");
    EXPECT_TRUE(ans);
}