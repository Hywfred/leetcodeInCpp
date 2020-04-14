//
// Created by Hywfred on 2020/3/23.
//

#ifndef LEETCODEINCPP_LISTNODE_H
#define LEETCODEINCPP_LISTNODE_H

#include <iostream>
#include <vector>
using  namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* NewList(vector<int>& input) {
    int len = input.size();
    if (!len) {
        return nullptr;
    }
    ListNode* head = new ListNode(input[0]);
    ListNode* walker = head;
    for (int i = 1; i < len; ++i) {
        ListNode *tmp = new ListNode(input[i]);
        walker->next = tmp;
        walker = walker->next;
    }
    return head;
}

void Print(ListNode* head) {
    if (!head) {
        return;
    }
    ListNode* walker = head;
    while (walker) {
        cout << walker->val << " ";
        walker = walker->next;
    }
    cout << endl;
}

#endif //LEETCODEINCPP_LISTNODE_H
