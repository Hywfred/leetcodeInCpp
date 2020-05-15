#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, subarray_sum_k) {
    vector<int> data{1, 1, 1};
    Solution s;
    auto ans = s.subarraySum(data, 2);
    EXPECT_EQ(ans, 2);

    data = {1, 1, 1, 1, -1, -1};
    ans = s.subarraySum(data, 2);
    EXPECT_EQ(ans, 5);

    data = {};
    ans = s.subarraySum(data, 0);
    EXPECT_EQ(ans, 0);

    data = {1};
    ans = s.subarraySum(data, 0);
    EXPECT_EQ(ans, 0);
}