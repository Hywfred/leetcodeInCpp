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

    // 硬币
    int waysToChange(int n);

    // 数组中的逆序对
    int reversePairs(std::vector<int> &nums);

    // 全排列
    std::vector<std::vector<int>> permute(std::vector<int> &nums);

    // 合并 K 个排序链表
    ListNode *mergeKLists(std::vector<ListNode *> &lists);
};

#endif  // _DAILY_H
