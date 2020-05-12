#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, min_stack) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    auto ans = minStack.getMin();  // --> 返回 -3.
    EXPECT_EQ(ans, -3) << "ans is " << ans;
    minStack.pop();
    ans = minStack.top();     // --> 返回 0.
    EXPECT_EQ(ans, 0) << "ans is " << ans;
    ans = minStack.getMin();  // --> 返回 -2.
    EXPECT_EQ(ans, -2) << "ans is " << ans;
}