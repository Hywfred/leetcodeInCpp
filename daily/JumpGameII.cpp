/**
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:
假设你总是可以到达数组的最后一个位置。
 */
#include "daily.h"

using namespace std;

int Solution::jump(vector<int>& nums) {
    int count = 0;
    int maxPos = 0;
    int end = 0;
    for (decltype(nums.size()) i = 0; i < nums.size() - 1; ++i) {
        int tmp = i + nums[i];
        maxPos = maxPos > tmp ? maxPos : tmp;
        if (i == end) {
            end = maxPos;
            ++count;
        }
    }
    return count;
}

/**
 * 超时版本
 * helper 返回当前节点跳至最后一个位置的最小跳跃次数
 */
int helperTimeout(const vector<int> &nums, int begPos) {
    // 结束条件
    if (begPos + nums[begPos] >= nums.size() - 1) {
        return 1;
    }
    auto counts = nums.size();
    for (decltype(nums.size()) i = begPos + 1; i <= begPos + nums[begPos]; ++i) {
        int tmp = helperTimeout(nums, i) + 1;
        counts = counts < tmp ? counts : tmp;
    }
    return counts;
}

/**
 * 超时版本
 */
int jumpTimeout(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    return helperTimeout(nums, 0);
}