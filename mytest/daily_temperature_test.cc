#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, daily_temperature) {
    Solution s;
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    auto ans = s.dailyTemperatures(T);
    vector<int> wanted{1, 1, 4, 2, 1, 1, 0, 0};
    EXPECT_EQ(ans, wanted);

    T = {73};
    ans = s.dailyTemperatures(T);
    wanted = {0};
    EXPECT_EQ(ans, wanted);

    T = {73, 73, 75, 71, 69};
    ans = s.dailyTemperatures(T);
    wanted = {2, 1, 0, 0, 0};
    EXPECT_EQ(ans, wanted);
}