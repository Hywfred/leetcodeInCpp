#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, maximal_square) {
    Solution s;
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    auto ans = s.maximalSquare(matrix);
    EXPECT_EQ(ans, 4);

    matrix = {{'1'}};
    ans = s.maximalSquare(matrix);
    EXPECT_EQ(ans, 1);
}