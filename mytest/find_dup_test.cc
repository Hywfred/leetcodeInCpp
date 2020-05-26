#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, find_dup) {
    Solution s;
    vector<int> data{1, 3, 4, 2, 2};
    auto ans = s.findDuplicate(data);
    EXPECT_EQ(ans, 2);

    data = {3, 1, 3, 4, 2};
    ans = s.findDuplicate(data);
    EXPECT_EQ(ans, 3);
}