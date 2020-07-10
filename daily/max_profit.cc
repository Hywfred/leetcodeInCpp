/**
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
示例:
输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 */
#include <algorithm>

#include "daily.h"

using namespace std;

/**
 * 思路：动态规划
 */
int Solution::maxProfit(vector<int> &prices) {
    int len = prices.size();
    if (len <= 1) return 0;
    // dp[i][j] 代表第 i 天在 j 状态下的最大利润
    // j 代表今天持有股票的状态，0 为未持有，1 为持有
    vector<vector<int>> dp(len + 1, vector<int>(2));
    dp[0][0] = 0, dp[0][1] = INT_MIN;
    dp[1][0] = 0;
    dp[1][1] = -prices[0];
    for (int i = 2; i <= len; ++i) {
        // 今天未持有的最大利润是以下两者中的最大值：
        // 1. 昨天未持有
        // 2. 昨天持有，今天卖出
        dp[i][0] = max(dp[i - 1][1] + prices[i - 1], dp[i - 1][0]);  // 今天未持有
        // 如果今天持有，其中就有一种可能就是今天买的，那么就必须考虑前天的状态
        // 因为前天的状态会影响今天的行为：
        // 1. 昨天持有
        // 2. 昨天未持有，此时只能考虑前天未持有状态。否则违反冷冻期规定
        // 而昨天未持有，前天未持有的收益需要重新计算
        dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
    }
    return dp[len][0];
}
