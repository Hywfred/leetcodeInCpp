/**
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O (log (m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
 */
#include "daily.h"

using namespace std;

/**
 * 时间复杂度为 O(m+n) 的解法
 */
double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    double ans = 0.0;
    vector<int> nums(nums1.size() + nums2.size());
    size_t l1 = 0, l2 = 0, k = 0;
    while (l1 < nums1.size() && l2 < nums2.size()) {
        if (nums1[l1] < nums2[l2]) {
            nums[k] = nums1[l1];
            ++l1, ++k;
        } else {
            nums[k] = nums2[l2];
            ++l2, ++k;
        }
    }
    while (l1 < nums1.size()) {
        nums[k] = nums1[l1];
        ++l1, ++k;
    }
    while (l2 < nums2.size()) {
        nums[k] = nums2[l2];
        ++l2, ++k;
    }
    return nums.size() & 0x01 ? nums[nums.size() / 2] : (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
}