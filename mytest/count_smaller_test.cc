#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, count_smaller) {
    Solution s;
    vector<int> input{5, 2, 6, 1};
    vector<int> wanted{2, 1, 1, 0};
    auto ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {26, 78, 27, 100, 33, 67, 90, 23, 66, 5,  38, 7,  35, 23, 52, 22, 83, 51, 98,  69,
             81, 32, 78, 28,  94, 13, 2,  97, 3,  76, 99, 51, 9,  21, 84, 66, 65, 36, 100, 41};
    wanted = {10, 27, 10, 35, 12, 22, 28, 8,  19, 2, 12, 2, 9, 6, 12, 5, 17, 9, 19, 12,
              14, 6,  12, 5,  12, 3,  0,  10, 0,  7, 8,  4, 0, 0, 4,  3, 2,  0, 1,  0};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {1, 2, 0};
    wanted = {1, 1, 0};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {};
    wanted = {};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {1};
    wanted = {0};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {1, 2};
    wanted = {0, 0};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);

    input = {3, 2};
    wanted = {1, 0};
    ans = s.countSmaller(input);
    EXPECT_EQ(ans, wanted);
}