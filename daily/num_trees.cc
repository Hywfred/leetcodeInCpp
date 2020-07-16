/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
#include "daily.h"

using namespace std;

/**
 * 动态规划
 */
int Solution::numTrees(int n) {
    if (n <= 0) return 0;
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // n 为奇数
        if (i % 2) {
            for (int j = 0; j < i / 2; ++j) dp[i] += 2 * dp[j] * dp[i - j - 1];
            dp[i] += dp[i / 2] * dp[i / 2];
        } else {
            // n 为偶数
            for (int j = 0; j < i / 2; ++j) dp[i] += 2 * dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

/**
 * 递归 + memo
 */
// int helper(int first, int last, vector<vector<int>> &memo) {
//     if (last - first == 1) return 2;                  // 两个数时，共有两种可能
//     if (first == last) return 1;                      // 只有一个数时数量，只有一种可能
//     if (first > last) return 0;                       // 不合法 返回 0
//     if (memo[first][last]) return memo[first][last];  // 如果已经计算过了，直接返回，放置重复计算
//     int ans = 0;
//     // 开始计算，让每个元素作为根结点
//     for (int i = first; i <= last; ++i) {
//         int left = helper(first, i - 1, memo);
//         left = left ? left : 1;
//         int right = helper(i + 1, last, memo);
//         right = right ? right : 1;
//         ans += left * right;
//     }
//     memo[first][last] = ans;  // 记录当前结果
//     return ans;
// }

// int Solution::numTrees(int n) {
//     if (n < 0) return 0;
//     vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
//     return helper(1, n, memo);
// }