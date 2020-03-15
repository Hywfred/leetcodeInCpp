//
// Created by Hywfred on 2020/3/9.
//

#ifndef LEETCODEINCPP_SORT_H
#define LEETCODEINCPP_SORT_H

#include <vector>

using namespace std;

class Sort {
public:
    /**
     * 冒泡排序 原理：
     * 每次第一个元素与后面的元素比较，如果大于后面元素则交换
     * 第一次循环，最大元素处于最后位置，n-i轮排序结束后即可。
     * @param input 待排序整数序列
     */
    void Bubble(vector<int> &input) {
        int length = input.size();
        for (int i = 0; i < length - 1; ++i) {
            for (int j = 0; j < length - 1 - i; ++j) {
                if (input[j] > input[j + 1]) {
                    int tmp = input[j];
                    input[j] = input[j+1];
                    input[j+1] = tmp;
                }
            }
        }
    }

    /**
     * 选择排序 原理：
     * 每次循环，选出最小值与头部元素交换位置
     * 与冒泡排序相比，少了很多交换次数，效率要好一些。
     * @param input
     */
    void Select(vector<int>& input) {
        int length = input.size();
        for (int i = 0; i < length - 1; ++i) {
            int min = i;
            for (int j = i + 1; j < length; ++j) {
                if (input.at(j) < input.at(min)) {
                    min = j;
                }
            }
            // 找到最小值索引，交换 min 和 i 的值
            int tmp = input.at(i);
            input.at(i) = input.at(min);
            input.at(min) = tmp;
        }
    }

    /**
     * 插入排序
     * 从第2个元素开始，每次假设前面的序列已经排好序，找到第i个元素的位置插入，其他的后移一位即可。
     * @param input
     */
    void Insert(vector<int>& input) {
        if (input.size() <= 1) {
            return;
        }
        for (int i = 1; i < input.size(); ++i) {
            int tmp = input[i];
            int j = i - 1;
            while (j >= 0 && tmp < input[j]) {
                input[j+1] = input[j];
                --j;
            }
            if (j + 1 != i) {
                input[j + 1] = tmp;
            }
        }
    }

    /**
     * 希尔排序
     * 按增量进行插入排序，直至增量减小为1.
     * @param input
     */
    void Shell(vector<int>& input) {
        int length = input.size();
        for (int gap = length / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < length; ++i) {
                int cur = input[i];
                int j = i- gap;
                while (j >= 0 && cur < input[j]) {
                    input[j + gap] = input[j];
                    j -= gap;
                }
                if (j + gap != i) {
                    input[j + gap] = cur;
                }
            }
        }
    }


    /**
     * 大顶堆下沉，此操作建立在大顶堆已经建立的基础上
     * @param arr
     * @param curIndex
     * @param end
     */
    void SiftDown(vector<int>& arr, int curIndex, int end) {
        int left = curIndex * 2 + 1; // 左孩子
        while (left <= end) { // 左孩子存在
            int swap = curIndex; // 需要交换的元素下标
            if (arr[left] > arr[curIndex]) {
                swap = left;
            }
            // 如果有右孩子并且右孩子值大于当前最大值
            if (left + 1 <= end && arr[left+1] > arr[swap]) {
                swap = left + 1;
            }
            // 需要交换
            if (swap != curIndex) {
                int tmp = arr[curIndex];
                arr[curIndex] = arr[swap];
                arr[swap] = tmp;
                curIndex = swap;
                left = curIndex * 2 + 1;
            } else {
                return;
            }
        }
    }
    /**
     * 堆排序
     * 利用堆结构进行排序，每次选择大顶堆的堆定与最后的元素交换
     * 接着调整大顶堆，继续上一步操作
     * @param input 
     */
    void Heap(vector<int>& input) {
        int length = input.size();
        // 构建大顶堆
        for (int last = length / 2 - 1; last >= 0; --last) {
            SiftDown(input, last, length);
        }
        // 堆排序
        int end = length - 1;
        while (end > 0) {
            // 交换堆顶与最后一个元素
            int tmp = input[end];
            input[end] = input[0];
            input[0] = tmp;
            // 缩小范围
            --end;
            // 调整大顶堆
            SiftDown(input, 0, end);
        }
    }
    //***************归并排序****************//
    void merge(vector<int>& input, int left, int middle, int right, vector<int>& tmp) {
        int l = left;
        int r = middle + 1;
        int k = 0;
        while (l <= middle && r <= right) {
            if (input[l] < input[r]) {
                tmp[k++] = input[l++];
            } else {
                tmp[k++] = input[r++];
            }
        }
        while (l <= middle) {
            tmp[k++] = input[l++];
        }
        while (r <= right) {
            tmp[k++] = input[r++];
        }
        k = 0;
        while (left <= right) {
            input[left++] = tmp[k++];
        }
    }
    /**
     * 归并排序 递归调用
     * @param input 输入数组
     * @param left 左边界
     * @param right 右边界
     */
    void mergeSort(vector<int>& input, int left, int right, vector<int>& tmp) {
        if (left < right) {
            int middle = left + (right - left) / 2;
            mergeSort(input, left, middle, tmp);
            mergeSort(input, middle+1, right, tmp);
            merge(input, left, middle, right, tmp);
        }
    }
    /**
     * 归并排序
     * 分治策略 分而治之，跟二叉树有某种关联 但是没想明白
     * @param input
     */
    void Merge(vector<int>& input) {
        int length = input.size();
        vector<int> tmp (length);
        mergeSort(input, 0, length - 1, tmp);
    }

    //********** 快速排序 **********//
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void quickSort(vector<int>& input, int left, int right) {
        if (left >= right) {
            return;
        }
        int target = input[left];
        int l = left ;
        int r = right;
        while (l < r) {
            while (l < r && input[r] >= target) {
                r--;
            }
            while (l < r && input[l] <= target) {
                l++;
            }
            if (l < r) {
                swap(input[l], input[r]);
            }
        }
        if (l != left) {
            swap(input[l], input[left]);
        }
        quickSort(input, left, l-1);
        quickSort(input, l+1, right);
    }
    /**
     * 快速排序
     * 分治 递归
     * @param input
     */
    void Quick(vector<int>& input) {
        quickSort(input, 0, input.size() - 1);
    }

};


#endif //LEETCODEINCPP_SORT_H
