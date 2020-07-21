#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, two_sum) {
    Solution s;
    vector<int> input{2, 7, 11, 15};
    vector<int> wanted{1, 2};
    auto ans = s.twoSum(input, 9);
    EXPECT_EQ(wanted, ans);

    input = {2, 7, 11, 15};
    wanted = {3, 4};
    ans = s.twoSum(input, 26);
    EXPECT_EQ(wanted, ans);
}