#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, product_except_self) {
    Solution s;
    vector<int> input{1, 2, 3, 4};
    vector<int> wanted{24, 12, 8, 6};
    auto ans = s.productExceptSelf(input);
    EXPECT_EQ(ans, wanted);

    input = {2, 3};
    wanted = {3, 2};
    ans = s.productExceptSelf(input);
    EXPECT_EQ(ans, wanted);
}