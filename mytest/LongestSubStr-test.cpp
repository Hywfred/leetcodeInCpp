#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, longest_sub_str) {
    Solution s;
    auto ans = s.lengthOfLongestSubstring("");
    EXPECT_EQ(ans, 0);
    ans = s.lengthOfLongestSubstring("a");
    EXPECT_EQ(ans, 1);
    ans = s.lengthOfLongestSubstring("abcdefg");
    EXPECT_EQ(ans, 7);
    ans = s.lengthOfLongestSubstring("abcabcbb");
    EXPECT_EQ(ans, 3);
    ans = s.lengthOfLongestSubstring("bbbbb");
    EXPECT_EQ(ans, 1);
    ans = s.lengthOfLongestSubstring("pwwkew");
    EXPECT_EQ(ans, 3);
    ans = s.lengthOfLongestSubstring("tmmzuxt");
    EXPECT_EQ(ans, 5);
}