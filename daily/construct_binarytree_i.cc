/**
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
 */
#include <algorithm>

#include "daily.h"

using namespace std;

/**
 * 此版本超时，考虑进行优化。
 */
TreeNode *constructTreeTimeout(const vector<int> &pre, const vector<int> &in, vector<int>::const_iterator beg,
                               vector<int>::const_iterator end) {
    // 退出条件
    if (beg >= end) return nullptr;
    TreeNode *root = new TreeNode(*beg);
    auto root_it = find(in.cbegin(), in.cend(), *beg);
    auto right_beg = find_if(beg, end, [&](int val) { return find(in.cbegin(), in.cend(), val) > root_it; });
    root->left = constructTreeTimeout(pre, in, beg + 1, right_beg);
    root->right = constructTreeTimeout(pre, in, right_beg, end);
    return root;
}

/**
 * 优化思路：根结点左子树和右子树的节点数目是一样的。。
 */
TreeNode *constructTree(const vector<int> &pre, vector<int>::const_iterator beg, vector<int>::const_iterator end,
                        const vector<int> &in, vector<int>::const_iterator inBeg, vector<int>::const_iterator inEnd) {
    // 退出条件
    if (beg >= end || inBeg >= inEnd) return nullptr;
    TreeNode *root = new TreeNode(*beg);
    auto root_it = find(inBeg, inEnd, *beg);
    root->left = constructTree(pre, beg + 1, (root_it - inBeg) + beg + 1, in, inBeg, root_it);
    root->right = constructTree(pre, (root_it - inBeg) + beg + 1, end, in, root_it + 1, inEnd);
    return root;
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // 边界情况
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return nullptr;
    return constructTree(preorder, preorder.cbegin(), preorder.end(), inorder, inorder.cbegin(), inorder.cend());
}