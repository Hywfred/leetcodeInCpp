//
// Created by Hywfred on 2020/3/13.
//
//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//示例 1:
//输入: [3,2,3]
//输出: 3
//示例 2:
//输入: [2,2,1,1,1,2,2]
//输出: 2
#ifndef LEETCODEINCPP_MAJORITYELEMENT_H
#define LEETCODEINCPP_MAJORITYELEMENT_H

#include <map>
using  namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        map<int, int> res;
        for (int i = 0; i < nums.size(); ++i) {
            res[nums[i]]++;
        }
        for (auto it = res.begin(); it != res.end(); ++it) {
            if (it->second > nums.size()/2) {
                ans = it->first;
            }
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_MAJORITYELEMENT_H
