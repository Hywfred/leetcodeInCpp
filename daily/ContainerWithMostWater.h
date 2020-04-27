//
// Created by Hywfred on 2020/4/18.
//
//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//说明：你不能倾斜容器，且 n 的值至少为 2。
//图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//示例：
//输入：[1,8,6,2,5,4,8,3,7]
//输出：49
#ifndef LEETCODEINCPP_CONTAINERWITHMOSTWATER_H
#define LEETCODEINCPP_CONTAINERWITHMOSTWATER_H

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto beg = height.begin(), end = height.end() - 1;
        // 初始面积
        int maxArea = static_cast<int>(end - beg) * min(*beg, *end);
        int curShorter; // 代表当前左右两条线中的较短的一个
        while (beg != end) {
            // 移动较短的一端
            if (*beg > *end) {
                curShorter = *end;
                while (--end != beg && *end <= curShorter);
            } else {
                curShorter = *beg;
                while (++beg != end && *beg <= curShorter);
            }
            // 找到当前的较短的一条线
            curShorter = min(*beg, *end);
            // 看看是否需要更新当前最大面积
            maxArea = max(maxArea, static_cast<int>(end - beg) * curShorter);
        }
        return maxArea;
    }
};
#endif //LEETCODEINCPP_CONTAINERWITHMOSTWATER_H
