#include "196.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, arithmetic) {
    vector<int> input{3, 5, 1};
    auto ans = canMakeArithmeticProgression(input);
    EXPECT_TRUE(ans);

    input = {1, 2};
    ans = canMakeArithmeticProgression(input);
    EXPECT_FALSE(ans);

    input = {9, 1, 3, 7, 5};
    ans = canMakeArithmeticProgression(input);
    EXPECT_TRUE(ans);
}