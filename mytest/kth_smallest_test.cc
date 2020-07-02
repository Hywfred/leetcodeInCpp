#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, kth_smallest) {
    Solution s;
    vector<vector<int>> matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    auto ans = s.kthSmallest(matrix, 8);
    EXPECT_EQ(ans, 13);

    matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    ans = s.kthSmallest(matrix, 7);
    EXPECT_EQ(ans, 13);

    matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    ans = s.kthSmallest(matrix, 9);
    EXPECT_EQ(ans, 15);

    matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    ans = s.kthSmallest(matrix, 1);
    EXPECT_EQ(ans, 1);

    matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    ans = s.kthSmallest(matrix, 2);
    EXPECT_EQ(ans, 5);

    matrix = {{1, 5}, {10, 11}};
    ans = s.kthSmallest(matrix, 4);
    EXPECT_EQ(ans, 11);

    matrix = {{1, 5}, {10, 11}};
    ans = s.kthSmallest(matrix, 1);
    EXPECT_EQ(ans, 1);

    matrix = {{1, 5}, {10, 11}};
    ans = s.kthSmallest(matrix, 2);
    EXPECT_EQ(ans, 5);

    matrix = {{1}};
    ans = s.kthSmallest(matrix, 1);
    EXPECT_EQ(ans, 1);
}