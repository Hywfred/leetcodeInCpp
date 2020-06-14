/**
给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value
的值变成 value后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
请注意，答案不一定是 arr 中的数字。
示例 1：
输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
示例 2：
输入：arr = [2,3,5], target = 10
输出：5
示例 3：
输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361
提示：
1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
 */
#include <algorithm>

#include "daily.h"

using namespace std;

int find_min(const vector<int> &arr) {
    int min_idx = 0;
    for (int i = 1; i != arr.size(); ++i) {
        if (arr[i] < arr[min_idx]) min_idx = i;
    }
    return min_idx;
}

/**
 * brute force
 */
int Solution::findBestValue(vector<int> &arr, int target) {
    // 排序
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int quo = target / len;  // 商
    int idx = 0;
    if (arr[idx] > quo)
        if (abs(len * quo - target) <= abs(len * (quo + 1) - target))
            return quo;
        else
            return quo + 1;
    else {
        while (true) {
            // 如果比到最后一个元素，那么返回最后的差值 target 和 最后一个元素之间小的那个。
            if (idx >= len - 1) return arr[idx] > target ? target : arr[idx];
            target -= arr[idx];
            ++idx;
            quo = target / (len - idx);
            if (arr[idx] <= quo) { continue; }
            // 第一个大于商 quo 的数
            if (abs(quo * (len - idx) - target) <= abs((quo + 1) * (len - idx) - target))
                return quo;
            else
                return quo + 1;
        }
    }
}