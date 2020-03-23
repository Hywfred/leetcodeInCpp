//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TREENODE_H
#define LEETCODEINCPP_TREENODE_H

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
// 根据数组构建二叉树
TreeNode* GenerateBT(vector<int>& arr, int start) {
    if (arr.empty() || start >= arr.size()) {
        return nullptr;
    }
    if (arr[start] == INT_MAX) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(arr.at(start));
    root->left = GenerateBT(arr, 2 * start + 1);
    root->right = GenerateBT(arr, 2 * start + 2);
}

// 前序遍历
void PreorderTraversal(TreeNode *root) {
	if (!root) {
		return;
	}
	cout << root->val << " ";
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}
// 中序遍历
void InorderTraversal(TreeNode *root) {
	if (!root) {
		return;
	}
	InorderTraversal(root->left);
	cout << root->val << " ";
	InorderTraversal(root->right);
}
#endif //LEETCODEINCPP_TREENODE_H
