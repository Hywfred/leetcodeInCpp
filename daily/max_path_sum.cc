/**
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
示例 1:
输入: [1,2,3]
       1
      / \
     2   3
输出: 6
示例 2:
输入: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
输出: 42
 */
#include <algorithm>

#include "daily.h"

using namespace std;

int max_val = INT_MIN;

int max_path(TreeNode *root) {
    if (!root) return 0;
    // 左右子树的最大路径和
    int left_max = max(0, max_path(root->left));
    int right_max = max(0, max_path(root->right));
    // 更新最大值
    max_val = max(max_val, left_max + root->val + right_max);
    // 因为要构成路径，所以必须考虑 root 的值
    return root->val + max(left_max, right_max);
}

int Solution::maxPathSum(TreeNode *root) {
    if (!root) return 0;

    max_path(root);
    return max_val;
}