#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, find_len) {
    Solution s;
    vector<int> A{1, 2, 3, 2, 1};
    vector<int> B{3, 2, 1, 4, 7};
    auto ans = s.findLength(A, B);
    EXPECT_EQ(ans, 3);

    A = {1};
    B = {3, 2, 5};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 0);

    A = {1, 2, 3};
    B = {5};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 0);

    A = {2};
    B = {2};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 1);

    A = {2, 4, 9};
    B = {2, 4, 9};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 3);

    A = {1, 2, 3, 2, 1, 5, 3, 2, 1, 4, 7};
    B = {3, 2, 1, 4, 7, 9};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 5);

    A = {0, 0, 0, 0, 0};
    B = {0, 0, 0, 0, 0};
    ans = s.findLength(A, B);
    EXPECT_EQ(ans, 5);
}