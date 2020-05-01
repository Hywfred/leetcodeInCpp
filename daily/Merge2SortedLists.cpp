/**
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
 */
#include "daily.h"

using namespace std;

/**
 * 参考题解 使用递归
 */
ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return l1 ? l1 : l2; // 如果至少有一个为空，则返回另一个
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

/**
 * 初始版本
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {  // 如果至少有一个为空，则返回另一个
        return l1 ? l1 : l2;
    }
    ListNode *head = nullptr;
    ListNode *walker1 = nullptr, *walker2 = nullptr;
    head = l1->val < l2->val ? (walker1 = l1->next, walker2 = l2, l1)
                             : (walker1 = l1, walker2 = l2->next, l2);
    ListNode *walker = head;
    while (walker1 && walker2) {
        if (walker1->val < walker2->val) {
            walker->next = walker1;
            walker = walker->next;
            walker1 = walker1->next;
        } else {
            walker->next = walker2;
            walker = walker->next;
            walker2 = walker2->next;
        }
    }
    if (walker1) {
        walker->next = walker1;
    } else {
        walker->next = walker2;
    }
    return head;
}