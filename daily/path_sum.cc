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
//  * 非递归遍历 //TODO
//  */
// bool hasPathSun(TreeNode *root, int sum) {
//     if (!root) return false;
//     stack<TreeNode *> nodes;
//     TreeNode *cur = root;
//     stack<int> vals;  // 记录处理过的值
//     int curSum = 0;
//     // 如果二叉树没有遍历完
//     while (cur || !nodes.empty()) {
//         while (cur) {
//             // 访问父节点

//             // 保存右子树
//             nodes.push(root->right);
//             // 访问左子树
//             cur = cur->left;
//         }
//         if (!nodes.empty()) {
//             cur = nodes.top();
//             nodes.pop();
//             if (vals.top() == sum && !cur->right) return true;
//             vals.pop();
//             cur = cur->right;
//         }
//     }
//     return false;
// }

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
