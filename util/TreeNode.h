//
// Created by Hywfred on 2020/3/4.
//

#ifndef LEETCODEINCPP_TREENODE_H
#define LEETCODEINCPP_TREENODE_H

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 根据数组构建二叉树
TreeNode *GenerateBT(std::vector<int> &arr);

// 前序遍历
std::ostream &PreorderTraversal(std::ostream &, TreeNode *root);
// 非递归前序遍历
void PreorderTraversal(TreeNode *root, std::vector<int> &ans);

// 中序遍历
void InorderTraversal(TreeNode *root);

// 层序遍历
void LevelTraversal(TreeNode *root);

#endif  // LEETCODEINCPP_TREENODE_H
