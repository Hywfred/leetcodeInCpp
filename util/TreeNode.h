//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TREENODE_H
#define LEETCODEINCPP_TREENODE_H

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
// 根据数组构建二叉树
TreeNode *GenerateBT(std::vector<int> &arr, int start);

// 前序遍历
void PreorderTraversal(TreeNode *root);

// 中序遍历
void InorderTraversal(TreeNode *root);

#endif //LEETCODEINCPP_TREENODE_H
