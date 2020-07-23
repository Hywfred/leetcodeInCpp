#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, min_path_sum) {
    Solution s;
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    auto ans = s.minPathSum(grid);
    EXPECT_EQ(ans, 7);

    grid = {};
    ans = s.minPathSum(grid);
    EXPECT_EQ(ans, 0);

    grid = {{1}};
    ans = s.minPathSum(grid);
    EXPECT_EQ(ans, 1);
}