/**
 * https://leetcode-cn.com/problems/minimum-path-sum/
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
 */
#include <algorithm>

#include "daily.h"

using namespace std;

/**
 * 思路：动态规划
 */
int Solution::minPathSum(vector<vector<int>> &grid) {
    int row = grid.size();
    if (!row) return 0;
    // 设置状态矩阵 dp[i][j] 代表从左上角到当前位置的最小路径和
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
                continue;
            }
            if (j == 0 && i > 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
                continue;
            }
            if (i > 0 && j > 0) dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[row - 1][col - 1];
}