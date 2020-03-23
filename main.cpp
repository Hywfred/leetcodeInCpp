#include <iostream>
#include "util/ListNode.h"
#include "daily/MiddleOfTheLinkedList.h"

using namespace std;

int main() {
    vector<int> input{1, 2, 3, 4, 5};
    input = {1, 2, 3, 4, 5, 6};
    auto head = NewList(input);
    Print(head);
    Solution s;
    auto ans = s.middleNode(head);
    Print(ans);
    return 0;
}