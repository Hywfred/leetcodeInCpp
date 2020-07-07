#include "TreeNode.h"

#include <iostream>

#include "gtest/gtest.h"

using namespace std;

TEST(mytest, treenode_test) {
    vector<int> ans;
    vector<int> data{1, 2, 5, 3, 4, 6, 7};
    auto root = GenerateBT(data);
    PreorderTraversal(root, ans);
    for (auto elem : ans) cout << elem << " ";
    cout << endl;
    // vector<int> input{1, 2, 3, 4, 5, 6, INT_MAX, 7};
    // auto root = GenerateBT(input);
    // LevelTraversal(root);
    // cout << endl;

    // input = {1, 2, 3, 4, 5, 6, 7};
    // root = GenerateBT(input);
    // LevelTraversal(root);
    // cout << endl;
}