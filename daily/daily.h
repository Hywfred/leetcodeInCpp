#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <string>
#include <vector>

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
};

#endif  // _DAILY_H