/**
 * https://leetcode-cn.com/problems/unique-paths-ii/
 */
#include "daily.h"

using namespace std;

/**
 * 考虑使用动态规划
 */
int Solution::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int row = obstacleGrid.size();
    if (!row) return 0;
    int col = obstacleGrid[0].size();
    if (obstacleGrid[row - 1][col - 1]) return 0;
    // dp[i][j] 代表从 start 到达下标为 i j 处的路径数量
    vector<vector<int>> dp(row, vector<int>(col));
    // 初始值确认，这里确认 1*n 的值
    bool foundone = false;
    for (int i = 0; i < col; ++i) {
        // 如果第一行碰到了 1，那么后面的路径个数均为 0
        if (foundone) continue;
        if (obstacleGrid[0][i]) {
            foundone = true;
            continue;
        }
        dp[0][i] = 1;  // 没有碰到 1，则路径个数为 1
    }
    // 从第 2 行(下标为 1)开始，确认所有 m*n 的路径个数
    for (int i = 1; i < row; ++i) {
        // 先找到该行到该元素位置的最后一个 1，1 前面的所有路径均不可达，为 0
        int lastone = -1;
        for (int k = 0; k < col; ++k) {
            // 如果当前元素为 1  则不可达
            if (obstacleGrid[i][k]) {
                dp[i][k] = 0;
                lastone = k;
                continue;
            }
            // 只有后面的路径才可达
            for (int j = lastone + 1; j <= k; ++j) dp[i][k] += dp[i - 1][j];
        }
    }
    return dp[row - 1][col - 1];
}