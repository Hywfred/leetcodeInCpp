//
// Created by Hywfred on 2020/4/14.
//
//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//进阶：
//如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
//示例：
//输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 8 -> 0 -> 7
#ifndef LEETCODEINCPP_ADDTWONUMBERS_H
#define LEETCODEINCPP_ADDTWONUMBERS_H

#include <stack>
#include "../util/ListNode.h"

class Solution {
public:
    // 思路：
    // 考虑使用栈进行存储数据
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int carrier = 0; // 进位
        ListNode *ans = nullptr; // 结果
        stack<int> s1, s2, s3; // 栈 用来存储 l1 和 l2 的数据以及结果数据
        // 存储链表节点的值
        ListNode *newL1 = new ListNode(0);
        ListNode *newL2 = new ListNode(0); // 这两句增加两个哑元，辅助计算
        newL1->next = l1;
        newL2->next = l2;
        ListNode *walker = newL1;
        while (walker) {
            s1.push(walker->val);
            walker = walker->next;
        }
        walker = newL2;
        while (walker) {
            s2.push(walker->val);
            walker = walker->next;
        }
        // 进行计算
        int smallerSize = -1;
        int size1 = s1.size(), size2 = s2.size();
        if (size1 > size2) smallerSize = size2;
        else smallerSize = size1; // 获取更短的栈的大小
        int v1 = 0, v2 = 0; // 辅助计算
        int sum = 0;
        while (smallerSize) {
            v1 = s1.top();
            s1.pop();
            v2 = s2.top();
            s2.pop();
            sum = v1 + v2 + carrier;
            if (sum >= 10) {
                sum = sum % 10;
                carrier = 1;
            } else {
                carrier = 0;
            }
            s3.push(sum); // 存储结果
            --smallerSize; // 更新 size
        }
        if (size1 > size2) {
            while (!s1.empty()) {
                v1 = s1.top();
                s1.pop();
                sum = v1 + carrier;
                if (sum >= 10) {
                    sum %= 10;
                    carrier = 1;
                } else {
                    carrier = 0;
                }
                s3.push(sum);
            }
        } else {
            while (!s2.empty()) {
                v2 = s2.top();
                s2.pop();
                sum = v2 + carrier;
                if (sum >= 10) {
                    sum %= 10;
                    carrier = 1;
                } else {
                    carrier = 0;
                }
                s3.push(sum);
            }
        }
        // 构建新链表
        if (s3.top() == 0) s3.pop();
        walker = new ListNode(s3.top());
        s3.pop();
        ans = walker;
        while (!s3.empty()) {
            ListNode *newNode = new ListNode(s3.top());
            s3.pop();
            walker->next = newNode;
            walker = newNode;
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_ADDTWONUMBERS_H
