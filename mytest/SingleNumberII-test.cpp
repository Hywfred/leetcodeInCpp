#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, single_number_ii) {
    vector<int> data{2, 2, 1};
    Solution s;
    auto ans = s.singleNumberII(data);
    EXPECT_EQ(ans, 1);

    data.assign({4, 1, 2, 1, 2});
    ans = s.singleNumberII(data);
    EXPECT_EQ(ans, 4);

    data.assign({5});
    ans = s.singleNumberII(data);
    EXPECT_EQ(ans, 5);
}