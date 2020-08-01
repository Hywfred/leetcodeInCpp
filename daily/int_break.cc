/**
 * https://leetcode-cn.com/problems/integer-break/
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
示例 1:
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
 */
#include "daily.h"

using namespace std;

/**
 * 采用动态规划
 */
int Solution::integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            int cur = j * dp[i - j];
            dp[i] = dp[i] > cur ? dp[i] : cur;
            cur = j * (i - j);
            dp[i] = dp[i] > cur ? dp[i] : cur;
        }
    }
    return dp[n];
}

/**
 * 采用记忆化方法进行优化
 */
// int helper(int n, vector<int> &memo) {
//     if (memo[n] != -1) return memo[n];
//     if (n <= 2) return 1;
//     int ans = 0;
//     int cur;
//     for (int i = 1; i < n; ++i) {
//         cur = i * helper(n - i, memo);
//         ans = cur > ans ? cur : ans;
//         ans = i * (n - i) > ans ? i * (n - i) : ans;
//     }
//     cout << "n: " << n << endl;
//     memo[n] = ans;
//     return ans;
// }

// int Solution::integerBreak(int n) {
//     vector<int> memo(n + 1, -1);
//     return helper(n, memo);
// }

/**
 * 递归：通过打印发现存在很多重复计算
 * 所以采用 记忆化 方法进行优化
 */
// int Solution::integerBreak(int n) {
//     if (n <= 2) return 1;
//     int ans = 0;
//     int cur;
//     for (int i = 1; i < n; ++i) {
//         cur = i * integerBreak(n - i);
//         ans = cur > ans ? cur : ans;
//         ans = i * (n - i) > ans ? i * (n - i) : ans;
//     }
//     cout << "n: " << n << endl;
//     return ans;
// }