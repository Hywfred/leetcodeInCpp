//
// Created by Hywfred on 2020/3/9.
//
//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明: 叶子节点是指没有子节点的节点。
//
//示例:
//给定二叉树 [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回它的最小深度  2.
#ifndef LEETCODEINCPP_MINIMUMDEPTHOFBT_H
#define LEETCODEINCPP_MINIMUMDEPTHOFBT_H

#include <algorithm>
#include "../../util/TreeNode.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lDepth = 1 + minDepth(root->left);
        int rDepth = 1 + minDepth(root->right);
        if (lDepth == 1 && 1 == rDepth) {
            return lDepth;
        }
        if (lDepth == 1) {
            return rDepth;
        }
        if (rDepth == 1) {
            return lDepth;
        }
        return min(lDepth, rDepth);
    }
};
#endif //LEETCODEINCPP_MINIMUMDEPTHOFBT_H
