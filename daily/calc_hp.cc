/**
 * https://leetcode-cn.com/problems/dungeon-game/
 * 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
    -2(K)	-3	   3
    -5	    -10	   1
    10	    30	   -5 (P)
 */
#include "daily.h"

using namespace std;

/**
 * 思路：动态规划
 * 好吧时间关系，下面的解法是错误的。哈哈~
 */
int Solution::calculateMinimumHP(vector<vector<int>> &dungeon) {
    int row = dungeon.size();
    if (!row) return 1;
    int col = dungeon[0].size();
    // dp[i][j] 代表在 i j 处所需的最小健康值
    // 该健康值必须是当前最佳路径上的健康值的最大值
    vector<vector<int>> dp(row, vector<int>(col));
    dp[0][0] = dungeon[0][0] < 0 ? 1 - dungeon[0][0] : 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!i && !j) continue;
            // 第一行
            if (!i && j > 0) {
                dungeon[i][j] += dungeon[i][j - 1];
                dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
                dp[i][j] = dp[i][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i][j];
                continue;
            }
            // 第一列
            if (!j && i > 0) {
                dungeon[i][j] += dungeon[i - 1][j];
                dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
                dp[i][j] = dp[i][j] < dp[i - 1][j] ? dp[i - 1][j] : dp[i][j];
                continue;
            }
            // 其余
            auto tmp = dungeon[i][j];
            dungeon[i][j] = dungeon[i - 1][j] + tmp;
            dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
            dp[i][j] = dp[i][j] < dp[i - 1][j] ? dp[i - 1][j] : dp[i][j];
            auto sum = dungeon[i][j - 1] + tmp;
            auto tmpdp = sum > 0 ? 1 : 1 - sum;
            tmpdp = tmpdp < dp[i][j - 1] ? dp[i][j - 1] : tmpdp;
            if (dp[i][j] > tmpdp) {
                dp[i][j] = tmpdp;
                dungeon[i][j] = sum;
            }
        }
    }
    return dp[row - 1][col - 1];
}