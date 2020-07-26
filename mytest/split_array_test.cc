#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, split_arr) {
    Solution s;
    vector<int> input{7, 2, 5, 10, 8};
    auto ans = s.splitArray(input, 2);
    EXPECT_EQ(ans, 18);

    input = {7, 2, 5, 10, 8};
    ans = s.splitArray(input, 5);
    EXPECT_EQ(ans, 10);

    input = {7, 2, 5, 10, 8};
    ans = s.splitArray(input, 3);
    EXPECT_EQ(ans, 14);

    input = {7, 2, 5, 10, 8, 45, 34, 23, 12, 89};
    ans = s.splitArray(input, 3);

    input = {7, 2, 5, 10, 8, 45, 34, 23, 12, 89};
    ans = s.splitArray(input, 5);
}