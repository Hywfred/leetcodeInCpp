#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, spiral_order) {
    Solution s;
    vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> wanted{1, 2, 3, 6, 9, 8, 7, 4, 5};
    auto ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    wanted = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {};
    wanted = {};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{}};
    wanted = {};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{1}};
    wanted = {1};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
             {11, 12, 13, 14, 15, 16, 17, 18, 19},
             {21, 22, 23, 24, 25, 26, 27, 28, 29},
             {31, 32, 33, 34, 35, 36, 37, 38, 39}};
    wanted = {1,  2,  3,  4,  5,  6,  7,  8,  9,  19, 29, 39, 38, 37, 36, 35, 34, 33,
              32, 31, 21, 11, 12, 13, 14, 15, 16, 17, 18, 28, 27, 26, 25, 24, 23, 22};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{1}, {2}, {3}, {4}, {5}, {6}, {7}};
    wanted = {1, 2, 3, 4, 5, 6, 7};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);

    input = {{1, 11}, {2, 22}, {3, 33}, {4, 44}, {5, 55}, {6, 66}, {7, 77}};
    wanted = {1, 11, 22, 33, 44, 55, 66, 77, 7, 6, 5, 4, 3, 2};
    ans = s.spiralOrder(input);
    EXPECT_EQ(ans, wanted);
}