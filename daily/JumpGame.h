//
// Created by Hywfred on 2020/4/17.
//
//给定一个非负整数数组，你最初位于数组的第一个位置。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个位置。
//示例 1:
//输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
//示例 2:
//输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
#ifndef LEETCODEINCPP_JUMPGAME_H
#define LEETCODEINCPP_JUMPGAME_H

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 关于问题的理解：
     * 如果一个位置可达，那么他之前所有的位置都可达。
     * 所以说，如果能跳到最后一个位置，那么就能跳到之前的任意一个位置
     * 也就是对所有的位置来说，跳到当前位置前的最远距离，一定大于等于当前位置
     * 否则改位置及后面的位置均不可达。
     * @param nums
     * @return
     */
    bool canJump(vector<int>& nums) {
        decltype(nums.size()) farest = 0; // 当前可达的最远位置
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            // 如果当前位置 i 不可达，那么之后的位置均不可达
            if (i > farest) return false;
            // 如果可达，那么更新可达的最远距离
            farest = max(farest, i + nums[i]);
        }
        return true;
    }
    /**
     * 超时版本，反面典型
     * @param nums
     * @return
     */
    bool canJumpTimeout(vector<int>& nums) {
        // 创建一个数组表示数组元素是否访问过
        vector<bool> visited(nums.size());
        auto vbeg = visited.begin();
        queue<vector<int>::const_iterator> Q;
        auto nBeg = nums.cbegin();
        auto nEnd = nums.end();
        Q.push(nBeg);
        *(vbeg) = true;
        while (!Q.empty()) {
            auto it = Q.front();
            Q.pop();
            if (*it >= nEnd - it - 1) {
                return true;
            }
            auto b = vbeg + (it - nBeg);
            int i = 1;
            while (i <= *it) {
                auto vit = b + i;
                if (!*(vit)){
                    if (*(it + i) >= nEnd - it - i - 1) {
                        return true;
                    }
                    Q.push(it + i);
                    *(vit) = true;
                }
                ++i;
            }
        }
        return false;
    }
};
#endif //LEETCODEINCPP_JUMPGAME_H
