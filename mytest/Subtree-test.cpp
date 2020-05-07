#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, subtree) {
    Solution s;
    vector<int> input{3, 4, 5, 1, 2, INT_MAX, INT_MAX};
    auto l1 = GenerateBT(input, 0);
    input = {4, 1, 2};
    auto l2 = GenerateBT(input, 0);
    auto ans = s.isSubtree(l1, l2);
    EXPECT_TRUE(ans);

    input = {1, 1};
    l1 = GenerateBT(input, 0);
    input = {1};
    l2 = GenerateBT(input, 0);
    ans = s.isSubtree(l1, l2);
    EXPECT_TRUE(ans);

    input = {3, 4, 5, 1, 2, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX};
    l1 = GenerateBT(input, 0);
    input = {4, 1, 2};
    l2 = GenerateBT(input, 0);
    ans = s.isSubtree(l1, l2);
    EXPECT_FALSE(ans);
}