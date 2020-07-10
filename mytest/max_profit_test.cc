#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, max_profit) {
    Solution s;
    vector<int> input{1, 2, 3, 0, 2};
    auto ans = s.maxProfit(input);
    EXPECT_EQ(ans, 3);
}