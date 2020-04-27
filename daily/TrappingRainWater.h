//
// Created by Hywfred on 2020/4/4.
//
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
//示例:
//输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6
//https://leetcode-cn.com/problems/trapping-rain-water/
#ifndef LEETCODEINCPP_TRAPPINGRAINWATER_H
#define LEETCODEINCPP_TRAPPINGRAINWATER_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int len = height.size();
        int left = 1, right = len - 2;
        int ans = 0;
        // left 左侧最高柱子
        int l_max = 0;
        // right 右侧最高柱子
        int r_max = 0;
        while (left <= right) {
            // 从左向右更新
            if (height[left - 1] < height[right + 1]) {
                l_max = max(l_max, height[left - 1]);
                if (l_max > height[left]) {
                    ans += l_max - height[left];
                }
                ++left;
            } else { // 从右向左更
                r_max = max(r_max, height[right + 1]);
                if (r_max > height[right]) {
                    ans += r_max - height[right];
                }
                --right;
            }
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_TRAPPINGRAINWATER_H
