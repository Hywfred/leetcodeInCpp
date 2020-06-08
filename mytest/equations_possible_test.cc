#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, equations_possible) {
    Solution s;
    vector<string> input{"a==b", "b!=a"};
    auto ans = s.equationsPossible(input);
    EXPECT_FALSE(ans);

    input = {"b==a", "a==b"};
    ans = s.equationsPossible(input);
    EXPECT_TRUE(ans);

    input = {"a==b", "b==c", "a==c"};
    ans = s.equationsPossible(input);
    EXPECT_TRUE(ans);

    input = {"a==b", "b!=c", "c==a"};
    ans = s.equationsPossible(input);
    EXPECT_FALSE(ans);

    input = {"c==c", "b==d", "x!=z"};
    ans = s.equationsPossible(input);
    EXPECT_TRUE(ans);

    input = {"a==b", "d==c", "a==b"};
    ans = s.equationsPossible(input);
    EXPECT_TRUE(ans);

    input = {"a==b", "d!=c", "a==c", "y==z", "y!=b", "d==b"};
    ans = s.equationsPossible(input);
    EXPECT_FALSE(ans);
}