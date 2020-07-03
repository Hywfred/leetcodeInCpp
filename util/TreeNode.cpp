#include "TreeNode.h"

#include <queue>

using namespace std;

// �������鹹��������
TreeNode *GenerateBT(vector<int> &arr) {
    if (arr.empty()) return nullptr;
    queue<TreeNode *> nodes;
    int idx = 0;
    TreeNode *root = new TreeNode(arr[idx]);
    nodes.push(root);

    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();
        if (++idx >= arr.size()) break;
        if (!node) continue;
        // left
        auto next = arr[idx];
        if (next != INT_MAX) {
            TreeNode *left = new TreeNode(next);
            node->left = left;
            nodes.push(left);
        }
        // right
        if (++idx >= arr.size()) break;
        next = arr[idx];
        if (next != INT_MAX) {
            TreeNode *right = new TreeNode(next);
            node->right = right;
            nodes.push(right);
        }
    }
    return root;
}

// ǰ�����
ostream &PreorderTraversal(ostream &os, TreeNode *root) {
    if (!root) { return os; }
    os << root->val << " ";
    PreorderTraversal(os, root->left);
    PreorderTraversal(os, root->right);
    return os;
}

// �������
void InorderTraversal(TreeNode *root) {
    if (!root) { return; }
    InorderTraversal(root->left);
    cout << root->val << " ";
    InorderTraversal(root->right);
}

// 层序遍历
void LevelTraversal(TreeNode *root) {
    if (!root) return;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();
        // 如果 node 为空
        if (!node) {
            cout << "null,";
            continue;
        } else {
            cout << node->val << ",";
        }
        nodes.push(node->left);
        nodes.push(node->right);
    }
}