/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6d
*/
#include <queue>

#include "daily.h"

using namespace std;

bool operator>(const ListNode &l1, const ListNode &l2) {
	return l1.val > l2.val;
}

struct cmp {
    bool operator()(const ListNode &n1, const ListNode &n2) {
        return n1.val > n2.val;
    }
};

ListNode *Solution::mergeKLists(std::vector<ListNode *> &lists) {
    priority_queue<ListNode, vector<ListNode>, cmp> q;
    ListNode *head = new ListNode(0);
    auto walker = head;
    for (auto elem : lists) {
        walker = elem;
        while (walker) {
            q.push(*walker);
            walker = walker->next;
        }
    }
    walker = head;
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        auto tmpNode = new ListNode(cur.val);
        walker->next = tmpNode;
        walker = walker->next;
    }
    return head->next;
}