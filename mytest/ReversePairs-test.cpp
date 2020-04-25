#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, ReversePair) {
    Solution s;
    vector<int> nums{7, 5, 6, 4};
    auto ans = s.reversePairs(nums);
    EXPECT_EQ(ans, 5);

    nums = {};
    ans = s.reversePairs(nums);
    EXPECT_EQ(ans, 0);

}