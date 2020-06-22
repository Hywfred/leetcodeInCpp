#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, pattern_matching) {
    // testing for gcd function
    // extern int gcd(int, int);
    // auto v = gcd(15, 9);
    // EXPECT_EQ(v, 3);
    // v = gcd(100, 42);
    // EXPECT_EQ(v, 2);
    // v = gcd(3, 1);
    // EXPECT_EQ(v, 1);
    // testing for patter matching

    Solution s;
    auto ans = s.patternMatching("abba", "dogcatcatfish");
    EXPECT_FALSE(ans);

    ans = s.patternMatching("abba", "dogcatcatdog");
    EXPECT_TRUE(ans);

    ans = s.patternMatching("aaaa", "dogcatcatdog");
    EXPECT_FALSE(ans);

    ans = s.patternMatching("abba", "dogdogdogdog");
    EXPECT_TRUE(ans);

    ans = s.patternMatching("a", "");
    EXPECT_TRUE(ans);

    ans = s.patternMatching("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", "p");
    EXPECT_FALSE(ans);
}