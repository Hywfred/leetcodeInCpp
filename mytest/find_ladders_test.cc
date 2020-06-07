#include "daily.h"
#include "gtest/gtest.h"
#include "my_iostream.h"

using namespace std;

TEST(mytest, find_ladders) {
    // Solution s;
    // vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};
    // auto ans = s.findLadders("hit", "cog", words);
    // for (const auto &elem : ans) {
    //     for (const auto &str : elem) { cout << str << " "; }
    //     cout << endl;
    // }
    // s1
    // Solution1 s1;
    // vector<string> words1{"hot", "dot", "dog", "lot", "log", "cog"};
    // auto ans1 = s1.findLadders("hit", "cog", words1);
    // for (const auto &elem : ans1) {
    //     for (const auto &str : elem) { cout << str << " "; }
    //     cout << endl;
    // }
    // print() EXPECT_EQ(ans, wanted);

    Solution s;
    vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};
    auto ans = s.findLadders("hit", "cog", words);
    for (const auto &elem : ans) {
        for (const auto &str : elem) { cout << str << " "; }
        cout << endl;
    }

    // words1 = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm",
    //           "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe",
    //           "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb",
    //           "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi",
    //           "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi",
    //           "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
    // ans1 = s1.findLadders("qa", "sq", words1);
    // for (const auto &elem : ans1) {
    //     for (const auto &str : elem) { cout << str << " "; }
    //     cout << endl;
    // }
}