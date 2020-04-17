//
// Created by Hywfred on 2020/4/16.
//
//给出一个区间的集合，请合并所有重叠的区间。
//示例 1:
//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//示例 2:
//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
#ifndef LEETCODEINCPP_MERGEINTERVALS_H
#define LEETCODEINCPP_MERGEINTERVALS_H

#include <vector>
#include <algorithm>
using std::vector;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
    return v1[0] < v2[0];
}

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // 结果矩阵
        if (intervals.empty()) return ans;
        // 判断 intervals 是否有序，如果没有则排序
        auto sorted = std::is_sorted(intervals.begin(), intervals.end(), cmp);
        if (!sorted) {
            std::sort(intervals.begin(), intervals.end(), cmp);
        }
        // 合并区间
        vector<int> cur{intervals[0]};
        decltype(intervals.size()) i = 0;
        while (i < intervals.size() - 1) {
            auto next = intervals[++i];
            if (next[0] <= cur[1]) { // 可以合并
                if (next[1] > cur[1])
                    cur[1] = next[1];
            } else {
                ans.push_back(cur);
                cur = next;
            }
        }
        // 判断一下最后两个是否合并
        ans.push_back(cur);
        return ans;
    }
};
#endif //LEETCODEINCPP_MERGEINTERVALS_H
