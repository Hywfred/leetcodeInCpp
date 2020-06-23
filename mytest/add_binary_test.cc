#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, add_binary) {
    Solution s;
    auto ans = s.addBinary("11", "1");
    EXPECT_EQ(ans, "100");

    ans = s.addBinary("1010", "1011");
    EXPECT_EQ(ans, "10101");

    ans = s.addBinary("1010", "10101101");
    EXPECT_EQ(ans, "10110111");

    ans = s.addBinary("110100101001", "1");
    EXPECT_EQ(ans, "110100101010");

    ans = s.addBinary("1111111", "1");
    EXPECT_EQ(ans, "10000000");
}