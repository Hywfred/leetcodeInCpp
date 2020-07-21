/**
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
示例：
输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
提示：
0 <= n <= 8
 */
#include "daily.h"

using namespace std;

vector<TreeNode *> helper(int left, int right) {
    if (right < left) return {};
    if (left == right) return {new TreeNode(left)};
    vector<TreeNode *> ans;
    for (int i = left; i <= right; ++i) {
        // 左子树
        auto left_child = helper(left, i - 1);
        auto right_child = helper(i + 1, right);
        if (left_child.empty()) {
            for (auto r : right_child) {
                auto root = new TreeNode(i);
                root->right = r;
                ans.push_back(root);
            }
        } else if (right_child.empty()) {
            for (auto l : left_child) {
                auto root = new TreeNode(i);
                root->left = l;
                ans.push_back(root);
            }
        } else {
            for (auto l : left_child) {
                for (auto r : right_child) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
    }
    return ans;
}

vector<TreeNode *> Solution::generateTrees(int n) { return helper(1, n); }