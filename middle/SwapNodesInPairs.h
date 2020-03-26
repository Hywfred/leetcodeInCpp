//
// Created by Hywfred on 2020/3/25.
//
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//示例:
//给定 1->2->3->4, 你应该返回 2->1->4->3.
#ifndef LEETCODEINCPP_SWAPNODESINPAIRS_H
#define LEETCODEINCPP_SWAPNODESINPAIRS_H

#include "../util/ListNode.h"
#include <stack>
using  namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 返回条件，如果为空或者只剩一个节点，则直接返回该节点。
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 调整指针
        ListNode* right = head->next;
        head->next = swapPairs(right->next); // 这里递归是核心
        right->next = head;
        // 返回头结点
        return right;
    }
};
#endif //LEETCODEINCPP_SWAPNODESINPAIRS_H
