//
// Created by Hywfred on 2020/3/31.
//
//给定一个整数数组 nums，将该数组升序排列。
//示例 1：
//输入：[5,2,3,1]
//输出：[1,2,3,5]
//示例 2：
//输入：[5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
//提示：
//1 <= A.length <= 10000
//-50000 <= A[i] <= 50000
#ifndef LEETCODEINCPP_SORTANARRAY_H
#define LEETCODEINCPP_SORTANARRAY_H

#include <vector>

using std::vector;

class Solution {
public:
    static void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    static void handlePivot(vector<int> &input, int left, int right) {
        if (left >= right)
            return;
        int middle = left + (right - left) / 2;
        if (input[left] > input[middle]) {
            swap(input[left], input[middle]);
        }
        if (input[left] > input[right]) {
            swap(input[left], input[right]);
        }
        if (input[middle] > input[right]) {
            swap(input[middle], input[right]);
        }
        if (right - 1 > middle) {
            swap(input[middle], input[right - 1]);
        }
    }

    static void quickSort(vector<int>& input, int left, int right) {
        if (left < right) {
            // 处理枢纽值
            handlePivot(input, left, right);
            // 快速排序
            int l = left;
            int r = right - 1;
            int pivot = right - 1;
            while (true) {
                // 从左侧开始
                while (input[++l] < input[pivot]);
                while (r > l && input[--r] > input[pivot]);
                if (r > l) {
                    swap(input[l], input[r]);
                } else {
                    break;
                }
            }
            // 交换枢纽值和 l 对应的值
            if (pivot > l) {
                swap(input[l], input[pivot]);
            }
            // 递归处理 middle 左侧和右侧
            quickSort(input, left, l-1);
            quickSort(input, l+1, right);
        }
    }
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};

#endif //LEETCODEINCPP_SORTANARRAY_H
