/**
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 */
#include <algorithm>
#include <limits>

#include "daily.h"

using namespace std;

int Solution::maxProduct(vector<int> &nums) {
    int len = nums.size();
    if (!len) return len;
    int ans = numeric_limits<int>::min();
    int cur_max = 1, cur_min = 1;
    for (decltype(len) i = 0; i < len; ++i) {
        if (nums[i] >= 0) {
            cur_max = max(cur_max * nums[i], nums[i]);
            cur_min = min(cur_min * nums[i], nums[i]);
        } else {
            int tmp = cur_max;
            cur_max = max(cur_min * nums[i], nums[i]);
            cur_min = min(tmp * nums[i], nums[i]);
        }
        ans = max(ans, cur_max);
    }
    return ans;
}