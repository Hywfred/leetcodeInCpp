#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, search_insert) {
    Solution s;
    vector<int> input{1, 3, 5, 6};
    auto ans = s.searchInsert(input, 5);
    EXPECT_EQ(ans, 2);

    ans = s.searchInsert(input, 2);
    EXPECT_EQ(ans, 1);

    ans = s.searchInsert(input, 7);
    EXPECT_EQ(ans, 4);

    ans = s.searchInsert(input, 0);
    EXPECT_EQ(ans, 0);

    input = {1};
    ans = s.searchInsert(input, 0);
    EXPECT_EQ(ans, 0);

    input = {1};
    ans = s.searchInsert(input, 2);
    EXPECT_EQ(ans, 1);

    input = {};
    ans = s.searchInsert(input, 2);
    EXPECT_EQ(ans, 0);
}