#pragma once
#ifndef _DAILY_H
#define _DAILY_H

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

    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

int findMountainTop(MountainArray &m);

#endif  // _DAILY_H