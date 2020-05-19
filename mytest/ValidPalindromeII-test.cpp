#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, valid_palindrome_ii) {
    Solution s;
    auto ans = s.validPalindrome("abcdcba");
    EXPECT_TRUE(ans) << "abcdcba" << endl;

    ans = s.validPalindrome("a");
    EXPECT_TRUE(ans) << "a" << endl;

    ans = s.validPalindrome("ab");
    EXPECT_TRUE(ans) << "ab" << endl;

    ans = s.validPalindrome("cc");
    EXPECT_TRUE(ans) << "cc" << endl;

    ans = s.validPalindrome("eabcdcba");
    EXPECT_TRUE(ans) << "eabcdcba" << endl;

    ans = s.validPalindrome("abcdcbae");
    EXPECT_TRUE(ans) << "abcdcbae" << endl;

    ans = s.validPalindrome("aebcdcba");
    EXPECT_TRUE(ans) << "aebcdcba" << endl;

    ans = s.validPalindrome("abcdceba");
    EXPECT_TRUE(ans) << "abcdceba" << endl;

    ans = s.validPalindrome("abcdcefba");
    EXPECT_FALSE(ans) << "abcdcefba" << endl;

    ans = s.validPalindrome("abc");
    EXPECT_FALSE(ans) << "abc" << endl;

    ans = s.validPalindrome("abcdfcba");
    EXPECT_TRUE(ans) << "abcdfcba" << endl;

    ans = s.validPalindrome("ebcbbececabbacecbbcbe");
    EXPECT_TRUE(ans) << "ebcbbececabbacecbbcbe" << endl;

    ans = s.validPalindrome("eeccccbebaeeabebccceea");
    EXPECT_FALSE(ans) << "eeccccbebaeeabebccceea" << endl;
}