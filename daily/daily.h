#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <string>
#include <vector>

#include "ListNode.h"
#include "TreeNode.h"

class Solution {
   public:
    int strStr(std::string haystack, std::string needle);

    std::vector<int> rightSideView(TreeNode *root);

    // 硬币 20.04.23
    int waysToChange(int n);

    // 数组中的逆序对  20.04.24
    int reversePairs(std::vector<int> &nums);

    // 全排列 20.04.25
    std::vector<std::vector<int>> permute(std::vector<int> &nums);

    // 合并 K 个排序链表 20.04.26
    ListNode *mergeKLists(std::vector<ListNode *> &lists);

    // 搜索旋转排序数组 20.04.27
    int search(std::vector<int>& nums, int target);

    // 数组中数字出现的次数 20.04.28
    std::vector<int> singleNumbers(std::vector<int>& nums);
};

#endif  // _DAILY_H