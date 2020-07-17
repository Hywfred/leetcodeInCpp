/**
 * https://leetcode-cn.com/problems/search-insert-position/
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0
 */
#include "daily.h"

using namespace std;

/**
 * 思路：已排序 --> 二分法 O(logN)
 */
int Solution::searchInsert(vector<int> &nums, int target) {
    int mid;
    int left = 0, right = nums.size();
    while (left < right) {
        mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}