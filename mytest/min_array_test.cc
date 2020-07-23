#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, min_array) {
    Solution s;
    vector<int> input{3, 4, 5, 1, 2};
    auto ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {2, 2, 2, 0, 1};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 0);

    input = {1};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {3, 4, 5};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 3);

    input = {9, 1, 2, 3, 4, 5, 6, 7, 8};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {3, 4, 5, 6, 7, 8, 1, 2};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {3, 1};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {3, 3, 3, 1, 3};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);

    input = {3, 1, 3, 3, 3};
    ans = s.minArray(input);
    EXPECT_EQ(ans, 1);
}