#include <climits>

#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, serialize_deserialize_binarytree) {
    Codec c;
    vector<int> input{1, 2, 3, INT_MAX, INT_MAX, 4, 5};
    TreeNode *root = GenerateBT(input);
    auto ans_s = c.serialize(root);
    EXPECT_EQ(ans_s, "1,2,3,null,null,4,5,null,null,null,null");
    auto ans_t = c.deserialize(ans_s);
    PreorderTraversal(ans_t);

    input = {5, 2, 3, INT_MAX, INT_MAX, 2, 4, 3, 1};
    root = GenerateBT(input);
    ans_s = c.serialize(root);
    EXPECT_EQ(ans_s, "5,2,3,null,null,2,4,3,1");
    ans_t = c.deserialize("5,2,3,null,null,2,4,3,1");
    PreorderTraversal(ans_t);
}