#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, is_bipartite) {
    Solution s;
    vector<vector<int>> input{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    auto ans = s.isBipartite(input);
    EXPECT_TRUE(ans);

    input = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    ans = s.isBipartite(input);
    EXPECT_FALSE(ans);

    input = {{1}, {0, 3}, {3}, {1, 2}};
    ans = s.isBipartite(input);
    EXPECT_TRUE(ans);
}