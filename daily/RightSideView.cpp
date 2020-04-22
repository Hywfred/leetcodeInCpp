/**
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 */
#include "daily.h"

using namespace std;

static void rightView(TreeNode *root, vector<int> &ans, int level) {
    // 退出条件
	if (!root) {
		return;
	}
    if (!root) return;
    if (ans.size() == level) ans.push_back(root->val);
    rightView(root->right, ans, level + 1);
    rightView(root->left, ans,level + 1);
}

// 二叉树右视图
std::vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    rightView(root, ans, 0);
    return ans;
}
