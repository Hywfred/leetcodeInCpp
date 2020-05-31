/**
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
*/
#include "daily.h"

using namespace std;

/**
 * 迭代解法
 */
bool Solution::iter_symmetric(TreeNode *root) {
    if (!root) return true;
    queue<TreeNode *> q;
    q.push(root->left), q.push(root->right);
    TreeNode *left, *right;
    while (!q.empty()) {
        left = q.front(), q.pop();
        right = q.front(), q.pop();
        if (!left && !right) continue;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        q.push(left->left), q.push(right->right);
        q.push(left->right), q.push(right->left);
    }
    return true;
}

/**
 * 递归解法
 */
bool symmetric(TreeNode *r1, TreeNode *r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    if (r1->val != r2->val) return false;
    return symmetric(r1->left, r2->right) && symmetric(r1->right, r2->left);
}

bool Solution::isSymmetric(TreeNode *root) { return symmetric(root, root); }