#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, kth_largest) {
    Solution s;
    vector<int> input{3, 2, 1, 5, 6, 4};
    auto ans = s.findKthLargest(input, 2);
    EXPECT_EQ(ans, 5);

    input = {3, 2, 1, 5, 6, 4};
    ans = s.findKthLargest(input, 3);
    EXPECT_EQ(ans, 4);

    input = {3, 2, 1, 5, 6, 4};
    ans = s.findKthLargest(input, 1);
    EXPECT_EQ(ans, 6);

    input = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    ans = s.findKthLargest(input, 4);
    EXPECT_EQ(ans, 4);

    input = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    ans = s.findKthLargest(input, 3);
    EXPECT_EQ(ans, 5);

    input = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    ans = s.findKthLargest(input, 4);
    EXPECT_EQ(ans, 4);

    input = {3};
    ans = s.findKthLargest(input, 1);
    EXPECT_EQ(ans, 3);
}