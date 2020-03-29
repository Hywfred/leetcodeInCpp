//
// Created by Hywfred on 2020/3/13.
//

#ifndef LEETCODEINCPP_INORDERTRAVERSAL_H
#define LEETCODEINCPP_INORDERTRAVERSAL_H

#include "../../util/TreeNode.h"
#include <stack>

using  namespace std;

class Solution {
public:
    // 迭代版本 失败
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        int white = 0;
        int gray = 1;
        stack<pair<int, TreeNode*>> s;
        s.push(make_pair(white,root));
        while (!s.empty())
        {
            int color = s.top().first;
            TreeNode* t = s.top().second;
            s.pop();
            if (t == NULL) continue;
            if (color == white)
            {
                s.push(make_pair(white, t->right));
                s.push(make_pair(gray, t));
                s.push(make_pair(white, t->left));
            }
            else ans.push_back(t->val);
        }
        return ans;
    }
    vector<int> inorderTraversalI(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    // 递归
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

#endif //LEETCODEINCPP_INORDERTRAVERSAL_H
