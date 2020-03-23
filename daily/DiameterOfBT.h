//
// Created by Hywfred on 2020/3/10.
//
// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
//示例 :
//给定二叉树
//          1
//         / \
//        2   3
//       / \
//      4   5
//返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
//注意：两结点之间的路径长度是以它们之间边的数目表示。
#ifndef LEETCODEINCPP_DIAMETEROFBT_H
#define LEETCODEINCPP_DIAMETEROFBT_H

#include <algorithm>
#include "../util/TreeNode.h"
using namespace std;

class Solution {
public:

    // 优化版本
    int diameterOfBinaryTreeII(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
//    int diameterOfBinaryTree(TreeNode* root) {
//        if (!root) {
//            return 0;
//        }
//        return max({maxDepth(root->left) + maxDepth(root->right), diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
//    }
    int maxDepth(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int ld = maxDepth(root->left, diameter);
        int rd = maxDepth(root->right, diameter);
        diameter = max(diameter, ld + rd);
        return 1 + max(ld, rd);
    }
};

#endif //LEETCODEINCPP_DIAMETEROFBT_H
