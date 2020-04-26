#include "ListNode.h"

using namespace std;

ListNode *NewList(const vector<int> &input) {
    int len = input.size();
    if (!len) {
        return nullptr;
    }
    ListNode *head = new ListNode(input[0]);
    ListNode *walker = head;
    for (int i = 1; i < len; ++i) {
        ListNode *tmp = new ListNode(input[i]);
        walker->next = tmp;
        walker = walker->next;
    }
    return head;
}

void Print(ListNode *head) {
    if (!head) {
        return;
    }
    ListNode *walker = head;
    while (walker) {
        cout << walker->val << " ";
        walker = walker->next;
    }
    cout << endl;
}
