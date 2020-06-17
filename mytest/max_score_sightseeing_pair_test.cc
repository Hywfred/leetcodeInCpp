#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, max_score) {
    Solution s;
    vector<int> A{8, 1, 5, 2, 6};
    auto ans = s.maxScoreSightseeingPair(A);
    EXPECT_EQ(ans, 11);

    A = {2, 2, 2};
    ans = s.maxScoreSightseeingPair(A);
    EXPECT_EQ(ans, 3);
}