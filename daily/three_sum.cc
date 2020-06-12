/**
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例： 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */
#include <algorithm>

#include "daily.h"

using namespace std;
/**
 * 思路：
 * 1. 先排序
 * 2. 利用两数之和
 * 时间复杂度为 O(N^2)
 */
vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    int len = nums.size();
    if (len < 3) return {};

    sort(nums.begin(), nums.end());  // 排序
    unordered_map<int, int> imap;
    for (int i = 0; i != len; ++i) imap[nums[i]] = i;
    vector<vector<int>> ans;
    auto it = nums.begin();
    for (int i = 0; i != len - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j != len; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            auto target = -nums[i] - nums[j];
            if (imap.count(target) && imap[target] > j) ans.push_back({nums[i], nums[j], target});
        }
    }
    return ans;
}

// /**
//  * 最后一轮查找使用二分查找
//  * 时间复杂度 O(N^2*logN)
//  */
// bool bin_find(const vector<int> &input, int left, int right, int target) {
//     int mid;
//     while (left < right) {
//         mid = left + (right - left) / 2;
//         if (input[mid] == target) return true;
//         if (target > input[mid])
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return input[left] == target;
// }
// vector<vector<int>> Solution::threeSum(vector<int> &nums) {
//     int len = nums.size();
//     if (len < 3) return {};
//     // 排序
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     for (int i = 0; i != len - 2; ++i) {
//         if (i > 0 && nums[i] == nums[i - 1]) continue;
//         for (int j = i + 1; j != len - 1; ++j) {
//             if (j > i + 1 && nums[j] == nums[j - 1]) continue;
//             int target = -nums[i] - nums[j];
//             if (bin_find(nums, j + 1, len - 1, target)) ans.push_back({nums[i], nums[j], target});
//         }
//     }
//     return ans;
// }