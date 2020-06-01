#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, kids_with_candies) {
    Solution s;
    vector<int> candies{2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> wanted{true, true, true, false, true};
    auto ans = s.kidsWithCandies(candies, extraCandies);
    EXPECT_EQ(ans, wanted);

    candies = {4, 2, 1, 1, 2};
    extraCandies = 1;
    wanted = {true, false, false, false, false};
    ans = s.kidsWithCandies(candies, extraCandies);
    EXPECT_EQ(ans, wanted);

    candies = {12, 1, 12};
    extraCandies = 10;
    wanted = {true, false, true};
    ans = s.kidsWithCandies(candies, extraCandies);
    EXPECT_EQ(ans, wanted);
}