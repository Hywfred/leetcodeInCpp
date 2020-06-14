#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, find_best_value) {
    Solution s;
    vector<int> input{4, 9, 3};
    auto ans = s.findBestValue(input, 10);
    EXPECT_EQ(ans, 3);

    input = {2, 3, 5};
    ans = s.findBestValue(input, 10);
    EXPECT_EQ(ans, 5);

    input = {60864, 25176, 27249, 21296, 20204};
    ans = s.findBestValue(input, 56803);
    EXPECT_EQ(ans, 11361);

    input = {1, 2, 3, 4};
    ans = s.findBestValue(input, 10);
    EXPECT_EQ(ans, 4);

    input = {1, 2, 3, 4};
    ans = s.findBestValue(input, 9);
    EXPECT_EQ(ans, 3);

    input = {1, 2, 3, 4};
    ans = s.findBestValue(input, 8);
    EXPECT_EQ(ans, 2);

    input = {1547, 83230, 57084, 93444, 70879};
    ans = s.findBestValue(input, 71237);
    EXPECT_EQ(ans, 17422);
}