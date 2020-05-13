#include <climits>

#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, level_order) {
    vector<int> data{3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    auto root = GenerateBT(data, 0);
    Solution s;
    auto ans = s.levelOrder(root);
    decltype(ans) expected = {{3}, {9, 20}, {15, 7}};
    int i = 0;
    for (const auto &elem : ans) {
        EXPECT_EQ(elem, expected[i++]);
    }
}