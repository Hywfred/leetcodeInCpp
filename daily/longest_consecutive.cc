/**
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
#include <algorithm>
#include <unordered_map>

#include "daily.h"

using namespace std;

int Solution::longestConsecutive(vector<int> &nums) {
    // 如果数组为空
    auto len = nums.size();
    if (!len) return len;
    // 数组不为空
    unordered_map<int, bool> visited;
    for (decltype(len) i = 0; i != len; ++i) visited[nums[i]] = false;
    int ans = 0;  // 存储结果
    int cur = 1;  // 包含当前元素的最长连续序列的长度
    for (decltype(len) i = 0; i != len; ++i) {
        if (visited[nums[i]]) continue;  // 如果已经访问过了，就直接跳过
        int num = nums[i];
        // 向上查找
        while (visited.find(++num) != visited.end()) {
            ++cur;
            visited[num] = true;
        }
        num = nums[i];
        // 向下查找
        while (visited.find(--num) != visited.end()) {
            ++cur;
            visited[num] = true;
        }
        // 更新结果
        ans = cur > ans ? cur : ans;
        cur = 1;
    }
    return ans;
}