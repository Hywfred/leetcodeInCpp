#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, sorted_array_toBST) {
    Solution s;
    vector<int> input{-10, -3, 0, 5, 9};
    auto ans = s.sortedArrayToBST(input);
    PreorderTraversal(cout, ans) << endl;

    input = {1};
    ans = s.sortedArrayToBST(input);
    PreorderTraversal(cout, ans) << endl;

    input = {};
    ans = s.sortedArrayToBST(input);
    PreorderTraversal(cout, ans) << endl;
}