/**
 * https://leetcode-cn.com/problems/path-sum/
 */
#include <stack>

#include "daily.h"

using namespace std;

bool Solution::hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    // root 为叶节点
    if (!root->left && !root->right) return sum == root->val;
    sum -= root->val;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

/**
 * 非递归遍历 //TODO
 */
bool hasPathSun(TreeNode *root, int sum) {
    stack<TreeNode *> nodes;
    stack<int> values;
    TreeNode *cur = root;
    int curSum = 0;
    while (cur || !nodes.empty()) {
        // 遍历左子树
        while (cur) {
            // 父节点入栈
            nodes.push(cur);
            curSum += cur->val;
            values.push(curSum);
            cur = cur->left;
        }
        if (!nodes.empty()) {
            // 访问根结点
            cur = nodes.top();
            nodes.pop();
            curSum = values.top();
            values.pop();
            if (curSum == sum && !cur->left && !cur->right) return true;
            // 遍历右子树
            cur = cur->right;
        }
    }
    return false;
}

/**
 * 非递归遍历一 //TODO
 */
// bool hasPathSun(TreeNode *root, int sum) {
//     if (!root) return false;
//     stack<pair<TreeNode *, int>> nodes;
//     nodes.push({root, false});
//     bool visited;
//     while (!nodes.empty()) {
//         root = nodes.top().first;
//         visited = nodes.top().second;
//         nodes.pop();
//         if (!root) continue;
//         if (visited) {
//             if (!root->left && !root->right)
//                 return curSum == sum;
//         } else {
//             nodes.push({root->right, false});
//             nodes.push({root->left, false});
//             nodes.push({root, true});
//         }
//     }
//     return false;
// }
