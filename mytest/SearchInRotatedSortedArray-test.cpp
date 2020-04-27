#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, searchInRotatedSortedArray) {
    Solution s;
    vector<int> input{4,5,6,7,0,1,2};
    auto ans = s.search(input, 0);
    EXPECT_EQ(ans, 4);
    ans = s.search(input, 3);
    EXPECT_EQ(ans, -1);
    input = {1, 3, 5};
    ans = s.search(input, 5);
    EXPECT_EQ(ans, 2);
    input = {5, 1, 3};
    ans = s.search(input, 3);
    EXPECT_EQ(ans, 2);
}