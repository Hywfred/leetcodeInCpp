//
// Created by Hywfred on 2020/3/6.
//

#ifndef LEETCODEINCPP_TREELEVELTRAVERSALII_H
#define LEETCODEINCPP_TREELEVELTRAVERSALII_H
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回其自底向上的层次遍历为：
//[
//  [15,7],
//  [9,20],
//  [3]
//]

#include <vector>
#include <queue>
#include <algorithm>
#include "../../util/treenode.h"
using namespace std;

class Solution {
public:
	// 迭代
	vector<vector<int>> levelOrderBottomI(TreeNode* root) {
		vector<vector<int >> result;
		if (!root) {
			return result;
		}
		int lineNum = 1;
		// 根结点入队
		queue<TreeNode *> q;
		q.push(root);
		// 如果队不为空
		while (!q.empty()) {
			vector<int> cur;
			int nextNum = 0;
			while (lineNum) {
				TreeNode *tmp(q.front());
				q.pop();
				// 记录结点值
				cur.push_back(tmp->val);
				lineNum--;
				if (tmp->left) {
					q.push(tmp->left);
					nextNum++;
				}
				if (tmp->right) {
					q.push(tmp->right);
					nextNum++;
				}
			}
			lineNum = nextNum;
			result.push_back(cur);
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
};

#endif //LEETCODEINCPP_TREELEVELTRAVERSALII_H
