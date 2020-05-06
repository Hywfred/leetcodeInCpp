#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, mincostTickets) {
    Solution s;
    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};
    auto ans = s.mincostTickets(days, costs);
    EXPECT_EQ(ans, 11);

    days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    ans = s.mincostTickets(days, costs);
    EXPECT_EQ(ans, 17);
}