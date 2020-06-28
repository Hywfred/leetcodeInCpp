#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, min_subarray_len) {
    Solution s;
    vector<int> input{2, 3, 1, 2, 4, 3};
    auto ans = s.minSubArrayLen(7, input);
    EXPECT_EQ(ans, 2);

    input = {2, 3, 1, 2, 4, 3};
    ans = s.minSubArrayLen(70, input);
    EXPECT_EQ(ans, 0);

    input = {9};
    ans = s.minSubArrayLen(7, input);
    EXPECT_EQ(ans, 1);

    input = {2, 4, 5, 7, 78, 4, 4, 4, 34, 5, 6, 6, 45545, 5, 43, 4, 4, 4, 43, 34, 5};
    ans = s.minSubArrayLen(100, input);
    EXPECT_EQ(ans, 1);

    input = {2, 3, 1, 2, 4, 3};
    ans = s.minSubArrayLen(14, input);
    EXPECT_EQ(ans, 6);
}