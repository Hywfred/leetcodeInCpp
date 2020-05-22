#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, construct_binarytree_i) {
    Solution s;
    vector<int> pre{3, 9, 20, 15, 7};
    vector<int> in{9, 3, 15, 20, 7};
    auto ans = s.buildTree(pre, in);
    PreorderTraversal(ans);
    cout << endl;

    pre = {3, 9, 2, 4, 20, 15, 7};
    in = {2, 9, 4, 3, 15, 20, 7};
    ans = s.buildTree(pre, in);
    PreorderTraversal(ans);
    cout << endl;
}