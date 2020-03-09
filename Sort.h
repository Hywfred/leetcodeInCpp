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
            for (int j = i + 1; j < length; ++j) {
                if (input[i] > input[j]) {
                    int tmp = input[i];
                    input[i] = input[j];
                    input[j] = tmp;
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
};


#endif //LEETCODEINCPP_SORT_H
