//
// Created by Hywfred on 2020/3/11.
//
//翻转一棵二叉树。
//示例：
//输入：
//     4
//   /   \
//  2     7
// / \   / \
//1   3 6   9
//输出：
//     4
//   /   \
//  7     2
// / \   / \
//9   6 3   1
#ifndef LEETCODEINCPP_INVERTTREE_H
#define LEETCODEINCPP_INVERTTREE_H

#include "../../util/TreeNode.h"
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        auto* newRoot = new TreeNode(root->val);
        newRoot->left = invertTree(root->right);
        newRoot->right = invertTree(root->left);
        return newRoot;
    }
};

#endif //LEETCODEINCPP_INVERTTREE_H
