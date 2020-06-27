/**
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
提示：
你的算法的时间复杂度应为 O (n)，并且只能使用常数级别的额外空间。
 */
#include "daily.h"

using namespace std;

/**
 * 思路：只能使用常数级别额外空间的话
 * 言外之意是提示可以利用已有的空间（+ 额外常数空间）
 */
int Solution::firstMissingPositive(vector<int> &nums) {
    int len = nums.size();
    int cur, tmp;  // cur 代表当前元素，tmp 为辅助元素
    for (int i = 0; i < len; ++i) {
        // 如果当前元素 cur 为非正整数
        // 或者 cur - 1 == i（已经在目标位置）时跳过
        cur = nums[i];
        if (cur <= 0 || cur - 1 == i) continue;
        if (cur > len) {
            nums[i] = -1;
            continue;
        }
        // 否则的话，我们将其放到目标位置
        while (cur > 0) {
            int next = cur - 1;               // 下一个位置
            if (next >= len) next = len - 1;  // 下一个位置越界的话，设为最后一个
            // 如果下一个已经满足条件则退出，放置造成环
            if (nums[next] == next + 1) break;
            // 交换当前元素和下一个元素
            tmp = nums[next];
            nums[next] = cur;
            cur = tmp;
        }
    }
    // 遍历数组，第一个不满足 nums[i] != i + 1 的位置对应的元素
    for (int i = 0; i < len; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }
    return len + 1;
}