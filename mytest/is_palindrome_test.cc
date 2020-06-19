#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_palindrome) {
    Solution s;
    auto ans = s.isPalindrome("A man, a plan, a canal: Panama");
    EXPECT_TRUE(ans);

    ans = s.isPalindrome("race a car");
    EXPECT_FALSE(ans);

    ans = s.isPalindrome("0P");
    EXPECT_FALSE(ans);

    ans = s.isPalindrome("1b1");
    EXPECT_TRUE(ans);
}