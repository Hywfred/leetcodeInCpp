/**
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 */
#include "daily.h"

using namespace std;

/**
 * 思路：动态规划
 * dp[i] 代表以 i 处元素结尾的子数组的最大值
 * 优化：因为当前状态只与前两个状态有关，可以优化空间
 */
int Solution::rob(vector<int> &nums) {
    auto len = nums.size();
    if (!len) return len;
    if (len == 1) return nums[0];
    // 初始值
    int pre = nums[0];
    int cur = nums[1] > nums[0] ? nums[1] : nums[0];
    for (decltype(len) i = 2; i < len; ++i) {
        int tmp = cur;
        cur = pre + nums[i] > cur ? pre + nums[i] : cur;
        pre = tmp;
    }
    return cur;
}

// int Solution::rob(vector<int> &nums) {
//     auto len = nums.size();
//     if (!len) return len;
//     if (len == 1) return nums[0];
//     vector<int> dp(len);
//     // 初始值
//     dp[0] = nums[0];
//     dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
//     for (decltype(len) i = 2; i < len; ++i) {
//         // 如果前面相邻的房子偷了
//         int cur = dp[i - 2] + nums[i];
//         // 前面房子没偷
//         int pre = dp[i - 1];
//         dp[i] = cur > pre ? cur : pre;
//     }
//     return dp[len - 1];
// }