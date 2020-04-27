//
// Created by Hywfred on 2020/3/24.
//
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//示例:
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6
#ifndef LEETCODEINCPP_MERGEKSORTEDLIST_H
#define LEETCODEINCPP_MERGEKSORTEDLIST_H

#include <vector>
#include <climits>
#include "../util/ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len < 1)
            return nullptr;
        ListNode* preHead = new ListNode(0);
        ListNode* tmp = preHead;
        while (true) {
            int nullnum = 0;
            int min = INT_MAX, index = -1;
            for (int i = 0; i < len; ++i) {
                if (lists[i] && lists[i]->val < min) {
                    index = i;
                    min = lists[i]->val;
                }
                // 如果该链表为空，则统计加一。
                if (!lists[i]) {
                    ++nullnum;
                }
            }
            // 如果均为空，则退出循环。
            if (nullnum == len) {
                break;
            }
            // 选出最小值，添加到新链表尾部。
            tmp->next = lists[index];
            lists[index] = lists[index]->next;
            tmp = tmp->next;
        }
        return preHead->next;
    }
};
#endif //LEETCODEINCPP_MERGEKSORTEDLIST_H
