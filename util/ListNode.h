//
// Created by Hywfred on 2020/3/23.
//
#ifndef LEETCODEINCPP_LISTNODE_H
#define LEETCODEINCPP_LISTNODE_H
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *NewList(std::vector<int> &input);
void Print(ListNode *head);
#endif //LEETCODEINCPP_LISTNODE_H
