#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, subarr_divby_k) {
    Solution s;
    vector<int> data{4, 5, 0, -2, -3, 1};
    auto ans = s.subarraysDivByK(data, 5);
    EXPECT_EQ(ans, 7);

    data = {-1, 2, 9};
    ans = s.subarraysDivByK(data, 2);
    EXPECT_EQ(ans, 2);
}