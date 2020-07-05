#include "196.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, last_moment) {
    vector<int> left{4, 3};
    vector<int> right{0, 1};
    auto ans = getLastMoment(4, left, right);
    EXPECT_EQ(ans, 4);

    left = {};
    right = {0, 1, 2, 3, 4, 5, 6, 7};
    ans = getLastMoment(7, left, right);
    EXPECT_EQ(ans, 7);

    left = {0, 1, 2, 3, 4, 5, 6, 7};
    right = {};
    ans = getLastMoment(7, left, right);
    EXPECT_EQ(ans, 7);

    left = {5};
    right = {4};
    ans = getLastMoment(9, left, right);
    EXPECT_EQ(ans, 5);

    left = {6};
    right = {0};
    ans = getLastMoment(6, left, right);
    EXPECT_EQ(ans, 6);
}