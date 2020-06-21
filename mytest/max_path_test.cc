#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

extern int max_val;

TEST(mytest, max_path) {
    Solution s;
    vector<int> input{1, 2, 3};
    auto root = GenerateBT(input);
    auto ans = s.maxPathSum(root);
    EXPECT_EQ(ans, 6);

    max_val = INT_MIN;
    input = {-10, 9, 20, INT_MAX, INT_MAX, 15, 7};
    root = GenerateBT(input);
    ans = s.maxPathSum(root);
    EXPECT_EQ(ans, 42);

    max_val = INT_MIN;
    input = {-3};
    root = GenerateBT(input);
    ans = s.maxPathSum(root);
    EXPECT_EQ(ans, -3);
}