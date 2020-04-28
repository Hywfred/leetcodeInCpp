#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, single_number) {
    Solution s;
    vector<int> input{4, 1, 4, 6};
    auto ans = s.singleNumbers(input);
    EXPECT_TRUE(ans[0] == 1 || ans[0] == 6);
    EXPECT_TRUE(ans[1] == 1 || ans[1] == 6);

    input = {1, 2, 10, 4, 1, 4, 3, 3};
    ans = s.singleNumbers(input);
    EXPECT_TRUE(ans[0] == 2 || ans[0] == 10);
    EXPECT_TRUE(ans[0] == 10 || ans[0] == 2);
}