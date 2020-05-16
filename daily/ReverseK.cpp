/**
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
示例：
给你这个链表：1->2->3->4->5
当 k = 3 时，应当返回: 3->2->1->4->5
说明：
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */
#include "daily.h"

using namespace std;

ListNode *Solution::reverseKGroup(ListNode *head, int k) {
    ListNode *kth = head;          // 指向第 k 个节点
    ListNode *tmp = nullptr;       // 辅助翻转的临时节点
    ListNode *nextHead = nullptr;  // 标记本次翻转开始节点
    ListNode *ans = head;
    bool first = true;

    while (kth) {
        // 找到第 k 个节点
        unsigned count = 1;
        while (kth && count < k) {
            kth = kth->next;
            ++count;
        }
        // 不足 k 个节点直接退出循环
        if (!kth) break;
        // 如果 kth 存在，开始翻转
        if (!first) nextHead->next = kth;
        nextHead = head;
        while (head != kth) {
            tmp = head;
            head = tmp->next;
            tmp->next = kth->next;
            kth->next = tmp;
        }
        // 翻转完毕，记录头节点
        if (first) {
            ans = head;
            first = false;
        }
        // 更新变量
        head = nextHead->next;
        kth = head;
    }
    return ans;
}