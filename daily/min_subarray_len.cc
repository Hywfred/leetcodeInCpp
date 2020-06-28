/**
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。
示例: 
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:
如果你已经完成了 O(n) 时间复杂度的解法，请尝试 O(n log n) 时间复杂度的解法。
 */
#include "daily.h"

using namespace std;

/**
 * 思路：滑动窗口
 */
int Solution::minSubArrayLen(int s, vector<int> &nums) {
    int ans = nums.size() + 1;
    int left = 0, right = 0;
    int sum = 0;
    while (right < nums.size()) {
        // 如果满足 sum < s，right 右移
        sum += nums[right];
        ++right;
        // 只要满足 sum >= s left 右移，并不断更新结果
        while (sum >= s) {
            int tmp_len = right - left;
            ans = tmp_len < ans ? tmp_len : ans;
            if (ans == 1) return ans;
            sum -= nums[left++];
        }
    }
    return ans == nums.size() + 1 ? 0 : ans;
}
// 初始代码 上面为优化后代码
// int Solution::minSubArrayLen(int s, vector<int> &nums) {
//     int ans = nums.size();
//     int left = 0, right = 0;
//     int sum = 0;
//     bool found = false;
//     while (true) {
//         // 如果满足 sum < s，right 右移
//         if (sum < s) {
//             if (right >= nums.size()) break;
//             sum += nums[right];
//             ++right;
//         } else {
//             found = true;
//             // 只要满足 sum >= s left 右移，并不断更新结果
//             while (sum >= s) {
//                 int tmp_len = right - left;
//                 ans = tmp_len < ans ? tmp_len : ans;
//                 if (ans == 1) return ans;
//                 sum -= nums[left++];
//             }
//         }
//     }
//     return found ? ans : 0;
// }