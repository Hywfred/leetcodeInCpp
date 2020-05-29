#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, decode_string) {
    Solution s;
    auto ans = s.decodeString("3[a]2[bc]");
    EXPECT_EQ(ans, "aaabcbc");

    ans = s.decodeString("3[a2[c]]");
    EXPECT_EQ(ans, "accaccacc");

    ans = s.decodeString("2[abc]3[cd]ef");
    EXPECT_EQ(ans, "abcabccdcdcdef");

    ans = s.decodeString("");
    EXPECT_EQ(ans, "");

    ans = s.decodeString("abcdefg");
    EXPECT_EQ(ans, "abcdefg");

    ans = s.decodeString("abc3[2[a9[yuyu4[i]]]]ififif");
    EXPECT_EQ(ans,
              "abcayuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiayuyuiiiiyuyuiiiiyuyuiiiiyuy"
              "uiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiayuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyu"
              "yuiiiiyuyuiiiiayuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiayuyuiiiiyuyuiiii"
              "yuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiayuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiiiiyuyuiii"
              "iyuyuiiiiyuyuiiiiyuyuiiiiififif");
}