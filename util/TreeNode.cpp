#include "TreeNode.h"

using namespace std;

// �������鹹��������
TreeNode *GenerateBT(vector<int> &arr, int start) {
    if (arr.empty() || start >= arr.size()) {
        return nullptr;
    }
    if (arr[start] == INT_MAX) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(arr.at(start));
    root->left = GenerateBT(arr, 2 * start + 1);
    root->right = GenerateBT(arr, 2 * start + 2);
	return root;
}

// ǰ�����
void PreorderTraversal(TreeNode *root) {
	if (!root) {
		return;
	}
	cout << root->val << " ";
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

// �������
void InorderTraversal(TreeNode *root) {
	if (!root) {
		return;
	}
	InorderTraversal(root->left);
	cout << root->val << " ";
	InorderTraversal(root->right);
}