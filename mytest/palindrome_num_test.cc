#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, palindrome_num) {
    Solution s;
    auto ans = s.isPalindrome(121);
    EXPECT_TRUE(ans);

    ans = s.isPalindrome(10);
    EXPECT_FALSE(ans);

    ans = s.isPalindrome(-121);
    EXPECT_FALSE(ans);

    ans = s.isPalindrome(0);
    EXPECT_TRUE(ans);

    ans = s.isPalindrome(-123);
    EXPECT_FALSE(ans);
}