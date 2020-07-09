#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, respace) {
    Solution s;
    vector<string> words{"looked", "just", "like", "her", "brother"};
    auto ans = s.respace(words, "jesslookedjustliketimherbrother");
    EXPECT_EQ(ans, 7);
}