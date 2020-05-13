/**
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
示例：
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
 */
#include "daily.h"

using namespace std;

void traversal(TreeNode *root, int level, vector<vector<int>> &ans) {
    if (!root) return;
    if (ans.size() < level + 1)
        ans.push_back(vector<int>{root->val});
    else
        ans[level].push_back(root->val);
    traversal(root->left, level + 1, ans);
    traversal(root->right, level + 1, ans);
}

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    traversal(root, 0, ans);
    return ans;
}