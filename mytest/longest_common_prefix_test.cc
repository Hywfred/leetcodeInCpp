#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, longest_common_prefix) {
    Solution s;
    vector<string> inputs{"flower", "flow", "flight"};
    auto ans = s.longestCommonPrefix(inputs);
    EXPECT_EQ(ans, "fl");

    inputs = {"flower", "", "flight"};
    ans = s.longestCommonPrefix(inputs);
    EXPECT_EQ(ans, "");

    inputs = {"dog", "racecar", "car"};
    ans = s.longestCommonPrefix(inputs);
    EXPECT_EQ(ans, "");

    inputs = {"dog", "doggy", "dogggggg"};
    ans = s.longestCommonPrefix(inputs);
    EXPECT_EQ(ans, "dog");
}