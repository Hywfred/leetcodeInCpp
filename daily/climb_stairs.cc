/**
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
 */
#include "daily.h"

using namespace std;

/**
 * 思路：动态规划
 */
int Solution::climbStairs(int n) {
    if (n <= 2) return n;
    // dp[i] 代表 爬到 i 阶一共有多少种方法
    // 由于只与前两步的结果有关，这里只用两个变量
    int pre = 1, cur = 2;
    int tmp;
    for (int i = 3; i <= n; ++i) {
        // 先保存当前量
        tmp = cur;
        // 下一个当前量 n 对应的结果为 n-1 与 n-2 的结果之和
        cur = pre + cur;
        pre = tmp;
    }
    return cur;
}