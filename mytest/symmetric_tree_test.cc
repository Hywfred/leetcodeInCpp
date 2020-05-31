#include <climits>

#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, symmetric_tree) {
    Solution s;
    vector<int> data{1, 2, 2, 3, 4, 4, 3};
    auto t = GenerateBT(data, 0);
    auto ans = s.isSymmetric(t);
    EXPECT_TRUE(ans);

    data = {1, 2, 2, INT_MAX, 3, INT_MAX, 3};
    t = GenerateBT(data, 0);
    ans = s.isSymmetric(t);
    EXPECT_FALSE(ans);

    data = {1, 2, 2, 3, 4, 4, 3};
    t = GenerateBT(data, 0);
    ans = s.iter_symmetric(t);
    EXPECT_TRUE(ans);

    data = {1, 2, 2, INT_MAX, 3, INT_MAX, 3};
    t = GenerateBT(data, 0);
    ans = s.iter_symmetric(t);
    EXPECT_FALSE(ans);
}