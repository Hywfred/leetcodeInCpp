#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <climits>
#include <string>
#include <vector>

#include "ListNode.h"
#include "TreeNode.h"

/**
 *  This is the MountainArray's API interface.
 *  You should not implement it, or speculate about its implementation
 */
class MountainArray {
  public:
    MountainArray(const std::vector<int> &arr) : m_arr(arr) {}
    int get(int index);
    int length();
    void set(const std::vector<int> &arr);

  private:
    std::vector<int> m_arr;
};

class Solution {
  public:
    Solution() : pre(LONG_MIN) {}

    void set_pre() {
      pre = LONG_MIN;
    }

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
    int search(std::vector<int> &nums, int target);

    // 数组中数字出现的次数 20.04.28
    std::vector<int> singleNumbers(std::vector<int> &nums);

    // 山脉数组 20.04.29
    int findInMountainArray(int target, MountainArray &mountainArr);

    // 快乐数 20.04.30
    bool isHappy(int n);

    // 合并两个有序链表 20.05.01
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

    // 无重复字符的最长子串 20.05.02
    int lengthOfLongestSubstring(std::string s);

    // 最大子序和 20.05.03
    int maxSubArray(std::vector<int> &nums);

    // 跳跃游戏 II 20.05.04
    int jump(std::vector<int> &nums);

    // 验证二叉搜索树 20.05.05
    bool isValidBST(TreeNode *root);

    // 最低票价 20.05.06
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs);

    // 另一棵树的子树 20.05.07
    bool isSubtree(TreeNode* s, TreeNode* t);

  private:
    long pre;
};

int findMountainTop(MountainArray &m);

#endif  // _DAILY_H