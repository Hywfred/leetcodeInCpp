#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, vowels) {
    Solution s;
    auto ans = s.findTheLongestSubstring("eleetminicoworoep");
    EXPECT_EQ(ans, 13);

    ans = s.findTheLongestSubstring("leetcodeisgreat");
    EXPECT_EQ(ans, 5);

    ans = s.findTheLongestSubstring("bcbcbc");
    EXPECT_EQ(ans, 6);
}