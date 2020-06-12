#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, three_sum) {
    Solution s;
    vector<int> input{-1, 0, 1, 2, -1, -4};
    auto ans = s.threeSum(input);
    vector<vector<int>> wanted{{-1, 0, 1}, {-1, -1, 2}};
    EXPECT_EQ(ans, wanted);
}