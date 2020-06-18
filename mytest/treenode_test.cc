#include "TreeNode.h"

#include "gtest/gtest.h"

using namespace std;

TEST(mytest, treenode_test) {
    vector<int> input{1, 2, 3, 4, 5, 6, INT_MAX, 7};
    auto root = GenerateBT(input);
    LevelTraversal(root);
    cout << endl;

    input = {1, 2, 3, 4, 5, 6, 7};
    root = GenerateBT(input);
    LevelTraversal(root);
    cout << endl;
}