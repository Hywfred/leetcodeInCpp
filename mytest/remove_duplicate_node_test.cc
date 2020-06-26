#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, remove_duplicate) {
    Solution s;
    vector<int> input{1, 2, 3, 3, 2, 1};
    auto head = NewList(input);
    cout << "before removed: ";
    Print(head);
    cout << endl;
    head = s.removeDuplicateNodes(head);
    cout << "after removed: ";
    Print(head);
    cout << endl;
    // 删除链表
    delete head;

    input = {1, 1, 1, 1, 2};
    head = NewList(input);
    cout << "before removed: ";
    Print(head);
    cout << endl;
    head = s.removeDuplicateNodes(head);
    cout << "after removed: ";
    Print(head);
    cout << endl;
    // 删除链表
    delete head;

    input = {1, 2, 3, 4, 5, 6, 6};
    head = NewList(input);
    cout << "before removed: ";
    Print(head);
    cout << endl;
    head = s.removeDuplicateNodes(head);
    cout << "after removed: ";
    Print(head);
    cout << endl;
    // 删除链表
    delete head;

    input = {1};
    head = NewList(input);
    cout << "before removed: ";
    Print(head);
    cout << endl;
    head = s.removeDuplicateNodes(head);
    cout << "after removed: ";
    Print(head);
    cout << endl;
    // 删除链表
    delete head;
}