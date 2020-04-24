/**
 * 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上 1000000007)
示例1:
 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
示例2:
 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1
说明：
注意:
你可以假设：
0 <= n (总金额) <= 1000000
 */
#include <iostream>
#include <vector>

#include "daily.h"
using namespace std;

static int coins[4]{1, 5, 10, 25};

static void change(int n, int &count, const int &lastVal) {
    // 退出条件
    if (!n) {
        ++count;
        return;
    }
    for (size_t i = 0; i < 4; i++) {
        if (n >= coins[i] && coins[i] <= lastVal)
            change(n - coins[i], count, coins[i]);
    }
}

int waysToChangeTimeout(int n) {
    if (!n) return 0;
    int count = 0;
    change(n, count, coins[3]);
    return count % 1000000007;
}

int Solution::waysToChange(int n) {
    // dp[i] 代表 i 有多少种凑法
    vector<int> dp(n + 1);
    dp[0] = 1;
    // 先遍历硬币，避免重复情况。
    for (int i = 0; i < 4; ++i) {
        for (int j = coins[i]; j <= n; ++j) {
            dp[j] += dp[j - coins[i]];
            dp[j] %= 1000000007;
        }
    }

    return dp[n];
}