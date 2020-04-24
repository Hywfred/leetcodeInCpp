/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例 1:
输入: [7,5,6,4]
输出: 5
限制：
0 <= 数组长度 <= 50000
*/

#include "daily.h"

using namespace std;

/**
 * 暴力解法 时间复杂度 O(N^2)
 * 概算法超时
 */
int reversePairsTimeout(vector<int> &nums) {
    int ans = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] > nums[j]) ++ans;
        }
    }
    return ans;
}

// 辅助数组，存放排序后的数据
vector<int> helper;
/**
 * 分而治之
 */
int merge_sort(vector<int> &nums, int left, int right) {
    if (left >= right) return 0;
    int middle = left + (right - left) / 2;
    // 分
    long long ans = merge_sort(nums, left, middle) + merge_sort(nums, middle + 1, right);
    // 治
    int l = left, r = middle + 1;
    int k = 0;
    while (l <= middle && r <= right) {
        // 左边的小，只排序
        if (nums[l] <= nums[r]) {
            helper[k] = nums[l];
            ++k;
            ++l;
        } else {
            helper[k] = nums[r];
            ++k;
            ++r;
            // 更新逆序对
            ans += middle - l + 1;
        }
    }
    // 剩余的均有序，直接排序即可
    while (l <= middle) helper[k++] = nums[l++];
    while (r <= right) helper[k++] = nums[r++];
    // 更新原数组
    k = 0;
    for (l = left; l <= right; ++l, ++k) nums[l] = helper[k];
    return ans;
}

/**
 * 采用归并排序 时间复杂度O(NlogN)
 */
int Solution::reversePairs(vector<int> &nums) {
    helper.assign(nums.size(), 0);
    auto ans = merge_sort(nums, 0, nums.size() - 1);
    return ans;
}