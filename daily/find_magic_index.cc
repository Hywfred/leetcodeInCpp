/**
 * https://leetcode-cn.com/problems/magic-index-lcci/
魔术索引。 在数组 A[0...n-1] 中，有所谓的魔术索引，满足条件 A[i] = i。
给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组 A 中找出一个魔术索引，如果没有，则返回 -1。
若有多个魔术索引，返回索引值最小的一个。
示例 1:
输入：nums = [0, 2, 3, 4, 5]
输出：0
说明: 0下标的元素为0
示例 2:
 输入：nums = [1, 1, 1]
 输出：1
说明:
nums 长度在 [1, 1000000] 之间
此题为原书中的 Follow-up，即数组中可能包含重复元素的版本
 */
#include "daily.h"

using namespace std;

/**
 * 对下面方法的优化
 */
int Solution::findMagicIndex(vector<int> &nums) {
    int index = 0;
    int len = nums.size();
    // 因为有序，所以当最大值 < 0 或者 最小值 > len - 1 时不存在魔术索引。
    if (nums[0] >= len || nums[len - 1] < 0) return -1;
    while (index < len) {
        if (nums[index] == index)
            return index;
        else if (nums[index] > index)
            index = nums[index];
        else
            ++index;
    }
    return index >= len ? -1 : index;
}

/**
 * 时间复杂度 O(N)
 */
// int Solution::findMagicIndex(vector<int> &nums) {
//     int index = -1;
//     int len = nums.size();
//     // 因为有序，所以当最大值 < 0 或者 最小值 > len - 1 时不存在魔术索引。
//     if (nums[0] >= len || nums[len - 1] < 0) return -1;
//     for (int i = 0; i < len; ++i) {
//         if (nums[i] == i) {
//             index = i;
//             break;
//         }
//     }
//     return index;
// }