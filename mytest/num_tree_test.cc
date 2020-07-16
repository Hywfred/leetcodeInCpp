#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, num_tree) {
    Solution s;
    auto ans = s.numTrees(3);
    EXPECT_EQ(ans, 5);

    ans = s.numTrees(-5);
    EXPECT_EQ(ans, 0);

    ans = s.numTrees(0);
    EXPECT_EQ(ans, 0);

    ans = s.numTrees(1);
    EXPECT_EQ(ans, 1);

    ans = s.numTrees(4);
    EXPECT_EQ(ans, 14);

    ans = s.numTrees(5);
    EXPECT_EQ(ans, 42);
}