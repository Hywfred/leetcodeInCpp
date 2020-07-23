/**
 * https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2]为 [1,2,3,4,5] 的一个旋转，该数组的最小值为 1。  
示例 1：
输入：[3,4,5,1,2]
输出：1
示例 2：
输入：[2,2,2,0,1]
输出：0
 */
#include "daily.h"

using namespace std;

/**
 * 第一个思路，顺序遍历
 * 时间复杂度O(N)，空间复杂度 O(1)
 * 缺点：该思路没有利用数组有序的特点，所以我们应当考虑
 * 时间复杂度为 O(logN) 的解法
 */
int minArray(vector<int> &numbers) {
    int len = numbers.size();
    if (!len) return -1;
    int min = numbers[0];
    for (int i = 1; i != len; ++i) {
        if (numbers[i] < min) min = numbers[i];
    }
    return min;
}

int Solution::minArray(vector<int> &numbers) {
    int len = numbers.size();
    if (!len) return -1;
    // 首先判断旋转数组是否本身有序
    if (numbers[0] < numbers[len - 1]) return numbers[0];  // 本身有序
    // 如果真的发生了旋转
    int left = 0, right = len - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        // 如果找到最小值，则返回
        // 最小值的特点为，它比前一个数要小
        if (mid > 0 && numbers[mid] < numbers[mid - 1]) return numbers[mid];
        // 如果没找到，那么分三种情况：要么在前半部分有序数组中，要么在后半部分有序数组中
        //
        // 1. 3 4 5 6 7 8 9 1 2 在前半部分，特点为 mid 处元素 > 最后一个元素
        // 2. 8 9 1 2 3 4 5 6 7 在后半部分，特点为 mid 处元素 < 最后一个元素
        // 以上面的特点为切入点，进行二分查找
        if (numbers[mid] > numbers[right])
            left = mid + 1;
        else if (numbers[mid] < numbers[right])
            right = mid;
        else
            --right;
    }
    return numbers[right];
}