#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, diving_board) {
    Solution s;
    auto ans = s.divingBoard(1, 2, 3);
    EXPECT_EQ(ans, vector<int>({3, 4, 5, 6}));

    ans = s.divingBoard(1, 2, 4);
    EXPECT_EQ(ans, vector<int>({4, 5, 6, 7, 8}));

    ans = s.divingBoard(1, 1, 0);
    EXPECT_EQ(ans, vector<int>({}));

    ans = s.divingBoard(1, 1, 4);
    EXPECT_EQ(ans, vector<int>({4}));
}