//
// Created by Hywfred on 2020/3/7.
//
/**
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5
 */
#ifndef LEETCODEINCPP_SORTEDARR2BST_H
#define LEETCODEINCPP_SORTEDARR2BST_H

#include "../util/treenode.h"
#include <vector>

using std::vector;

class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		TreeNode *root;
		return GenerateBST(nums, 0, nums.size() - 1);
	}

	TreeNode *GenerateBST(vector<int> &nums, int left, int right) {
		if (left > right) {
			return nullptr;
		}
		// 构建当前结点
		int middle = left + (right - left) / 2;
		auto *curNode = new TreeNode(nums.at(middle));
		curNode->left = GenerateBST(nums, left, middle - 1);
		curNode->right = GenerateBST(nums, middle + 1, right);
		return curNode;
	}
};

#endif //LEETCODEINCPP_SORTEDARR2BST_H
