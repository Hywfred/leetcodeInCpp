/**
给定一个包括 n 个整数的数组 nums 和
一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
提示：
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
 */
#include <algorithm>

#include "daily.h"

using namespace std;

/**
 * 优化：双指针
 */
int Solution::threeSumClosest(vector<int> &nums, int target) {
    // 排序
    sort(nums.begin(), nums.end());
    int ans = 100000;  // 存储结果
    int len = nums.size();
    int left, right;  // 左右指针
    int sum;          // 存储三数之和
    for (int i = 0; i <= len - 3; ++i) {
        left = i + 1, right = len - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return target;  // 如果和相等直接返回
            if (abs(sum - target) < abs(ans - target)) ans = sum;
            if (sum < target)
                ++left;
            else
                --right;
        }
    }
    return ans;
}

/**
 * 思路：
 * 1. 排序
 * 2. 两层循环进行遍历
 * 3. 内层循环利用二分法查找
 * 时间复杂度为 O(N^2logN)
 */
/**
 * 二分查找，如果元素存在，找到元素位置；元素不存在，找到元素插入的位置
 */
// int find(const vector<int> &nums, int left, int right, int target) {
//     int mid;
//     while (left < right) {
//         mid = left + (right - left) / 2;
//         if (nums[mid] == target) return mid;
//         if (nums[mid] < target)
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return left;
// }
// int Solution::threeSumClosest(vector<int> &nums, int target) {
//     // 排序
//     sort(nums.begin(), nums.end());
//     int len = nums.size();
//     int val;  // 目标值
//     int idx;  // 目标所在的下标
//     int ans = 100000;
//     for (int i = 0; i <= len - 3; ++i) {
//         for (int j = i + 1; j <= len - 2; ++j) {
//             val = target - nums[i] - nums[j];
//             idx = find(nums, j + 1, len - 1, val);
//             // 当前位置
//             if (val == nums[idx]) return target;
//             if (abs(val - nums[idx]) < abs(ans - target)) ans = nums[i] + nums[j] + nums[idx];
//             // 前一个位置
//             if (idx - 1 > j && abs(val - nums[idx - 1]) < abs(ans - target)) {
//                 ans = nums[i] + nums[j] + nums[idx - 1];
//             }
//         }
//     }
//     return ans;
// }