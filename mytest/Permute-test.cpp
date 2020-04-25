#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, permute) {
    Solution s;
    vector<int> nums{1, 2, 3};
    auto ans = s.permute(nums);
    vector<vector<int>> ref = {
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
    };
    EXPECT_EQ(ans, ref);
}