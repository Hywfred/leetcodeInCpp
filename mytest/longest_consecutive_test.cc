#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, longest_consecutive) {
    Solution s;
    vector<int> input{100, 4, 200, 1, 3, 2};
    auto ans = s.longestConsecutive(input);
    EXPECT_EQ(ans, 4);

    input = {50, 80, 1000, 2, 1};
    ans = s.longestConsecutive(input);
    EXPECT_EQ(ans, 2);

    input = {};
    ans = s.longestConsecutive(input);
    EXPECT_EQ(ans, 0);

    input = {50, 80, 1000, 2, 1, 999, 998, 4, 997};
    ans = s.longestConsecutive(input);
    EXPECT_EQ(ans, 4);

    input = {50, 80, 1000, 2, 1, 79, 78, 77, 76, 75, 51, 52, 53, 54, 55, 56};
    ans = s.longestConsecutive(input);
    EXPECT_EQ(ans, 7);
}