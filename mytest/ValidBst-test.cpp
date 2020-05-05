#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, valid_bst) {
    vector<int> data{5, 1, 4, INT_MAX, INT_MAX, 3, 6};
    auto root = GenerateBT(data, 0);
    Solution s;
    auto ans = s.isValidBST(root);
    EXPECT_FALSE(false) << "1 failed";

    s.set_pre();
    data = {4, 3, 5, 2, 6, INT_MAX, INT_MAX};
    root = GenerateBT(data, 0);
    ans = s.isValidBST(root);
    EXPECT_FALSE(false) << "2 failed";

    s.set_pre();
    data = {3, 1, 5, 0, 2, 4, 6};
    root = GenerateBT(data, 0);
    cout << endl;
    ans = s.isValidBST(root);
    EXPECT_TRUE(ans) << "3 failed";
}