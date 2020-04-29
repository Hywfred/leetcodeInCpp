/**
这是一个 交互式问题 
给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。
首先，A.length >= 3
其次，在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：
MountainArray.get(k) - 会返回数组中索引为 k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度
注意：
对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。
为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请注意这 不是一个正确答案。
示例 1：
输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。
示例 2：
输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。
提示：
3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9
*/
#include "daily.h"

inline int MountainArray::length() {
    return this->m_arr.size();
}

inline int MountainArray::get(int index) {
    if (index < this->m_arr.size()) {
        return m_arr[index];
    }
    return -1;
}
void MountainArray::set(const std::vector<int> &arr) {
    this->m_arr = arr;
}

/**
 * 通过二分法查找山顶值所在的索引
 */
int findMountainTop(MountainArray &m) {
    auto len = m.length();
    decltype(len) l = 0, r = len - 1;
    while (l < r) {
        decltype(len) mid = l + (r - l) / 2;
        if (m.get(mid) < m.get(mid + 1)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
/**
 * 通过二分法在升序数组中查找目标值
 */
int findInSorted(MountainArray &m, const int &target, const int &topIndex) {
    decltype(m.length()) l = 0, r = topIndex;
    while (l < r) {
        decltype(l) mid = l + (r - l) / 2;
        if (target > m.get(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (m.get(l) == target) {
        return l;
    }
    return -1;
}
/**
 * 通过二分法在降序数组中查找目标值
 */
int findInReverse(MountainArray &m, const int &target, const int &topIndex) {
    decltype(m.length()) l = topIndex, r = m.length() - 1;
    while (l < r) {
        decltype(l) mid = l + (r - l) / 2;
        if (target < m.get(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (m.get(l) == target) {
        return l;
    }
    return -1;
}
int Solution::findInMountainArray(int target, MountainArray &mountainArr) {
    auto topIndex = findMountainTop(mountainArr);
    if (mountainArr.get(topIndex) == target) return topIndex;
    int ans;
    if ((ans = findInSorted(mountainArr, target, topIndex)) != -1) return ans;
    return findInReverse(mountainArr, target, topIndex);
}