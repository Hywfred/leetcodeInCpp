#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, find_magic_index) {
    Solution s;
    vector<int> nums{0, 2, 3, 4, 5};
    auto ans = s.findMagicIndex(nums);
    EXPECT_EQ(ans, 0);

    nums = {1, 1, 1};
    ans = s.findMagicIndex(nums);
    EXPECT_EQ(ans, 1);

    nums = {1};
    ans = s.findMagicIndex(nums);
    EXPECT_EQ(ans, -1);

    nums = {0};
    ans = s.findMagicIndex(nums);
    EXPECT_EQ(ans, 0);
}