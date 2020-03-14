//
// Created by Hywfred on 2020/3/14.
//
//给定一个无序的整数数组，找到其中最长上升子序列的长度。
//示例:
//输入: [10,9,2,5,3,7,101,18]
//输出: 4
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
//说明:
//可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
//你算法的时间复杂度应该为 O(n2) 。
//进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
#ifndef LEETCODEINCPP_LONGESTINCRSEQ_H
#define LEETCODEINCPP_LONGESTINCRSEQ_H

#include <vector>
#include <algorithm>
using  namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int l = nums.size();
        vector<int> dp(l+1, 1);
        for (int i = 2; i <= l; ++i) {
            for (int j = 1; j < i; ++j) {
                if (nums[j - 1] < nums[i - 1]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }
        for (int i = 1; i <= l; ++i) {
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_LONGESTINCRSEQ_H
