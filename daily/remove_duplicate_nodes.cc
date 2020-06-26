/**
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
示例 1:
 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例 2:
 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：
链表长度在 [0, 20000] 范围内。
链表元素在 [0, 20000] 范围内。
进阶：
如果不得使用临时缓冲区，该怎么解决？
 */
#include <unordered_set>

#include "daily.h"

using namespace std;

ListNode *Solution::removeDuplicateNodes(ListNode *head) {
    if (!head) return head;      // 链表为空
    unordered_set<int> existed;  // 临时缓冲区
    ListNode *last;              // 存储上一个节点
    auto ans = head;             // 存储头结点
    while (head) {
        // 如果节点值重复
        if (existed.count(head->val)) {
            auto tmp = head;
            head = head->next;
            last->next = head;
            tmp->next = nullptr;
            delete tmp;
        } else {
            existed.insert(head->val);
            last = head;
            head = head->next;
        }
    }
    return ans;
}

/**
 * 如果不得使用临时缓冲区
 */

bool found(ListNode *head, ListNode *target) {
    if (!head) return false;
    while (head != target) {
        if (head->val == target->val) return true;
        head = head->next;
    }
    return false;
}

ListNode *removeDuplicateNodes(ListNode *head) {
    if (!head) return head;  // 链表为空
    // unordered_set<int> existed;  // 临时缓冲区
    ListNode *last;   // 存储上一个节点
    auto ans = head;  // 存储头结点
    while (head) {
        // 如果节点值重复
        // if (existed.count(head->val)) {
        if (found(ans, head)) {
            auto tmp = head;
            head = head->next;
            last->next = head;
            tmp->next = nullptr;
            delete tmp;
        } else {
            // existed.insert(head->val);
            last = head;
            head = head->next;
        }
    }
    return ans;
}