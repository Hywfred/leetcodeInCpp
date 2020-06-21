#include "194.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, file_uni) {
    vector<string> input{"pes", "fifa", "gta", "pes(2019)"};
    vector<string> want{"pes", "fifa", "gta", "pes(2019)"};
    auto ans = getFolderNames(input);
    EXPECT_EQ(ans, want);

    input = {"gta", "gta(1)", "gta", "avalon"};
    want = {"gta", "gta(1)", "gta(2)", "avalon"};
    ans = getFolderNames(input);
    EXPECT_EQ(ans, want);

    input = {"onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece"};
    want = {"onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece(4)"};
    ans = getFolderNames(input);
    EXPECT_EQ(ans, want);

    input = {"wano", "wano", "wano", "wano"};
    want = {"wano", "wano(1)", "wano(2)", "wano(3)"};
    ans = getFolderNames(input);
    EXPECT_EQ(ans, want);

    input = {"kaido", "kaido(1)", "kaido", "kaido(1)"};
    want = {"kaido", "kaido(1)", "kaido(2)", "kaido(1)(1)"};
    ans = getFolderNames(input);
    EXPECT_EQ(ans, want);

    input = {"kaido", "kaido(1)", "kaido", "kaido(1)", "kaido(2)"};
    want = {"kaido", "kaido(1)", "kaido(2)", "kaido(1)(1)", "kaido(2)(1)"};
    ans = getFolderNames(input);
    EXPECT_EQ(ans, want);
}