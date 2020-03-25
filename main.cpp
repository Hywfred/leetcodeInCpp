#include <iostream>
#include "hard/MergeKSortedList.h"
#include "util/ListNode.h"
#include "Sort.h"

using namespace std;

int main() {
    vector<int> ll1{1, 4, 5};
    vector<int> ll2{1, 3, 4};
    vector<int> ll3{2, 6};
    auto l1 = NewList(ll1);
    auto l2 = NewList(ll2);
    auto l3 = NewList(ll3);
    vector<ListNode*> input{l1, l2, l3};
    Solution s;
    auto res = s.mergeKLists(input);
    Print(res);
    return 0;
}