#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_palindrome_pairs) {
    Solution s;
    vector<string> data{"abcd", "dcba", "lls", "s", "sssll"};
    auto ans = s.palindromePairs(data);
    vector<vector<int>> wanted{{0, 1}, {1, 0}, {2, 4}, {3, 2}};
    EXPECT_EQ(ans, wanted);

    data = {"bat", "tab", "cat"};
    ans = s.palindromePairs(data);
    wanted = {{0, 1}, {1, 0}};
    EXPECT_EQ(ans, wanted);

    data = {};
    ans = s.palindromePairs(data);
    wanted = {};
    EXPECT_EQ(ans, wanted);
}