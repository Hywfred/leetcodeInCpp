/**
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O (n) 的解法，尝试使用更为精妙的分治法求解。
 */
#include "daily.h"

using namespace std;

/**
 * 第一次优化 空间复杂度优化为 O(1):
 * 当前状态只与上一次状态有关。
 * 时间复杂度为 O(N) 的解法，使用动态规划解决
 */
int Solution::maxSubArray(vector<int>& nums) {
    auto len = nums.size();
    if (!len) return len;
    int ans = nums.at(0);
    int sum = ans; // 代表上一次状态
    for (int i = 1; i < len; ++i) {
        if (sum < 0) sum = nums.at(i);
        else {
            sum += nums.at(i);
        }
        ans = sum > ans ? sum : ans;
    }
    return ans;
}

/**
 * 时间复杂度为 O(N) 的解法，使用动态规划解决
 */
// int Solution::maxSubArray(vector<int>& nums) {
//     auto len = nums.size();
//     if (!len) return len;
//     vector<int> dp(len); // 状态数组，dp[i] 代表第 i 个元素结尾的子序的最大和
//     dp[0] = nums.at(0);
//     int ans = dp[0];
//     for (int i = 1; i < len; ++i) {
//         if (dp[i-1] < 0) dp[i] = nums.at(i);
//         else {
//             dp[i] = dp[i-1] + nums.at(i);
//         }
//         ans = dp[i] > ans ? dp[i] : ans;
//     }
//     return ans;
// }