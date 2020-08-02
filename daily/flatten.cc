/**
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
给定一个二叉树，原地将它展开为一个单链表。
例如，给定二叉树
    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
[1,2,5,3,4,null,6]
[1,2,null,3,4,5]
[3,1,4,null,2]
 */
#include "daily.h"

using namespace std;

TreeNode *helper(TreeNode *root) {
    // 返回条件
    if (!root) return root;
    // 左子树展开
    auto left = helper(root->left);
    // 右子树展开
    auto right = helper(root->right);
    /*后序遍历，实行展开操作*/
    if (!left && !right) return root;
    if (!left) return right;
    if (!right) {
        auto tmp = root->left;
        root->left = nullptr;
        root->right = tmp;
        return left;
    }
    // 左子树右子树均不为空
    left->right = root->right;
    auto tmp = root->left;
    root->left = nullptr;
    root->right = tmp;
    return right;
}

void Solution::flatten(TreeNode *root) { helper(root); }