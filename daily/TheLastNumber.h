//
// Created by Hywfred on 2020/3/30.
//
//0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
//例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
//示例 1：
//输入: n = 5, m = 3
//输出: 3
//示例 2：
//输入: n = 10, m = 17
//输出: 2
//限制：
//1 <= n <= 10^5
//1 <= m <= 10^6
#ifndef LEETCODEINCPP_THELASTNUMBER_H
#define LEETCODEINCPP_THELASTNUMBER_H

#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }

    int lastRemainingTimeout2(int n, int m) {
        set<int> data;
        for (int i = 0; i < n; ++i) {
            data.insert(i);
        }
        int counter = 1;
        auto walker = data.begin();
        while (data.size() != 1) {
            while (counter < m) {
                ++counter;
                ++walker;
                if (walker == data.end()) {
                    walker = data.begin();
                }
            }

            auto tmp = data.erase(walker);
            walker = tmp == data.end() ? data.begin() : tmp;
            counter = 1;
        }
        return *data.begin();
    }

    int lastRemainingTimeout(int n, int m) {
        vector<int> data(n);
        for (int i = 0; i < n; ++i) {
            data[i] = i;
        }
        // 删除元素赋值为 -1
        int times = 0; // 删除 n-1 次
        int counter = 0; // 计数器
        int index = -1; // 删除元素的索引
        while (times != n-1) {
            while (++counter <= m) {
                while (true) {
                    ++index;
                    if (index == n) index = 0;
                    if (data[index] == -1) continue;
                    break;
                }
            }
            data[index] = -1;
            counter = 0;
            ++times;
        }
        index = -1;
        while (data[++index] == -1);
        return data[index];
    }
};
#endif //LEETCODEINCPP_THELASTNUMBER_H
