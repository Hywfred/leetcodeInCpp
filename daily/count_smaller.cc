/**
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
给定一个整数数组 nums，按要求返回一个新数组 counts。
数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i]的元素的数量。
示例:
输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1). 2 的右侧仅有 1
个更小的元素 (1). 6 的右侧有 1 个更小的元素 (1). 1 的右侧有 0 个更小的元素.
 */
#include <algorithm>
#include <unordered_map>

#include "daily.h"

using namespace std;

/**
 * 考虑优化 时间复杂度向 O(NlogN) 方向优化，这里考虑归并排序
 * 排序的过程中更新每个数字后面对应的比它小的数字个数
 * 最终时间复杂度为 O(NlogN)
 */

void merge(vector<pair<int, int>> &nums, int left, int right, vector<pair<int, int>> &res, vector<int> &counter) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge(nums, left, mid, res, counter);
        merge(nums, mid + 1, right, res, counter);
        // 开始比较并更新每个数后比它小的数的个数
        int l = left, r = mid + 1, i = 0;
        if (l == 0 && r == 10) {
            cout << "";
            cout << "";
        }
        int num = 0;  // 记录右侧比当前数小的个数
        while (l <= mid && r <= right) {
            // 如果右边的数不小于左边的数，只参与排序
            if (nums[l].first <= nums[r].first) {
                counter[nums[l].second] += num;
                res[i++] = nums[l++];
            } else {  // 如果右边的数小于左边的数，排序的同时更新左边数的个数
                ++num;
                res[i++] = nums[r++];
            }
        }
        while (l <= mid) {
            counter[nums[l].second] += num;
            res[i++] = nums[l++];
        }
        while (r <= right) res[i++] = nums[r++];
        i = 0, l = left;
        while (l <= right) nums[l++] = res[i++];
    }
}

vector<int> Solution::countSmaller(vector<int> &nums) {
    int len = nums.size();
    vector<pair<int, int>> res(len);                            // 用于辅助完成归并排序
    vector<int> ans(len);                                       // 用于存储结果
    vector<pair<int, int>> nums_copy(len);                      // 原数组的拷贝，并存储下标信息
    for (int i = 0; i < len; ++i) nums_copy[i] = {nums[i], i};  // 复制原数组并存储下标信息
    merge(nums_copy, 0, len - 1, res, ans);
    for (auto elem : nums_copy) { cout << elem.first << " "; }
    cout << endl;
    return ans;
}

// /**
//  * brute force
//  * 时间复杂度为 O(N^2) 超时
//  */
// vector<int> Solution::countSmaller(vector<int> &nums) {
//     int len = nums.size();
//     vector<int> ans(len);
//     int num;
//     for (int i = 0; i <= len - 2; ++i) {
//         num = 0;
//         for (int j = i + 1; j <= len - 1; ++j) {
//             if (nums[j] < nums[i]) ++num;
//         }
//         ans[i] = num;
//     }
//     return ans;
// }