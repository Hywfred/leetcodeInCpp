/**
 * https://leetcode-cn.com/problems/burst-balloons/
有 n 个气球，编号为 0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] *
nums[right] 个硬币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i
后，气球 left 和气球 right 就变成了相邻的气球。 求所能获得硬币的最大数量。
说明:
你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:
输入: [3,1,5,8]
输出: 167
解释: nums = [3,1,5,8] --> [3,5,8] --> [3,8] -->  [8]  --> []  
    coins =  3*1*5      +  3*5*8   +  1*3*8   + 1*8*1  = 167
 */
#include <list>

#include "daily.h"

using namespace std;

/**
 * 超时 时间复杂度为 O(N!)
 * 可怕
 */
void helper(vector<int> &nums, int &ans, int sum, int minus_num) {
    // 退出条件
    int len = nums.size();
    if (len == minus_num) {
        ans = sum > ans ? sum : ans;
        return;
    }
    int j;
    for (int i = 0; i < len; ++i) {
        if (nums[i] == -1) continue;
        j = i;
        // 左侧数
        while (--j >= 0 && nums[j] == -1)
            ;
        int left = j < 0 ? 1 : nums[j];
        // 右侧数
        j = i;
        while (++j < len && nums[j] == -1)
            ;
        int right = j >= len ? 1 : nums[j];
        // 设置当前位
        int tmp = nums[i];
        nums[i] = -1;
        helper(nums, ans, left * tmp * right + sum, minus_num + 1);
        // 回复当前位
        nums[i] = tmp;
    }
}

int Solution::maxCoins(vector<int> &nums) {
    int ans = 0;
    helper(nums, ans, 0, 0);
    return ans;
}