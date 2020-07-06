#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, unique_path) {
    Solution s;
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    auto ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 2);

    grid = {{0}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 1);

    grid = {{1}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 0);

    grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 0);

    grid = {{0, 0, 0, 0}, {0, 1, 0, 0}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 2);

    grid = {{0, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 2);

    grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
    ans = s.uniquePathsWithObstacles(grid);
    EXPECT_EQ(ans, 11);
}