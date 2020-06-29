/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 */
#include "daily.h"

using namespace std;

/**
 * 交换两数
 */
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/**
 * 节点下沉
 */
void siftDown(vector<int> &nums, int start, int end) {
    int left = start * 2 + 1;
    int largest;
    while (left <= end) {
        largest = start;
        // 此时节点有左孩子，判断是否需要更换最大位置
        if (nums[left] > nums[largest]) largest = left;
        // 判断 start 是否有右孩子，且是否需要更换最大位置
        if (left + 1 <= end && nums[left + 1] > nums[largest]) largest = left + 1;
        // 交换节点与最大节点
        if (start != largest)
            swap(nums[start], nums[largest]);
        else
            return;
        // 继续下沉
        start = largest;
        left = 2 * start + 1;
    }
}

int Solution::findKthLargest(vector<int> &nums, int k) {
    int len = nums.size();
    // 构建大顶堆
    for (int i = len / 2 - 1; i >= 0; --i) siftDown(nums, i, len - 1);
    // 挑选第 k 大的数
    int end = len - 1;
    while (end > 0) {
        // 交换堆顶与end元素
        swap(nums[0], nums[end]);
        // 找到第 k 大数后退出
        if (len - end >= k) break;
        // 更新 end
        --end;
        // 重塑大顶堆
        siftDown(nums, 0, end);
    }
    // 返回第 k 大数
    return nums[len - k];
}