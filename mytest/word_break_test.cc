#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, word_break) {
    Solution s;
    vector<string> input{"leet", "code"};
    auto ans = s.wordBreak("leetcode", input);
    EXPECT_TRUE(ans);

    input = {"apple", "pen"};
    ans = s.wordBreak("applepenapple", input);
    EXPECT_TRUE(ans);

    input = {"cats", "dog", "sand", "and", "cat"};
    ans = s.wordBreak("catsandog", input);
    EXPECT_FALSE(ans);

    input = {"abc", "jdfklj", "lkfj", "asdo", "lfjsa", "kldf", "jklsd"};
    ans = s.wordBreak("abcjdfkljlkfjasdolfjsakldfjklsd", input);
    EXPECT_TRUE(ans);

    input = {"abc", "jdfklj", "lkfj", "asdo", "lfjsa", "kldf", "jlsd", "abcjdfkljlkfjasdolfj", "sakldfjklsd"};
    ans = s.wordBreak("abcjdfkljlkfjasdolfjsakldfjklsd", input);
    EXPECT_TRUE(ans);

    input = {"a", "ab", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    ans = s.wordBreak(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        input);
    EXPECT_TRUE(ans);

    input = {"a", "aa", "aaa", "aaab", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    ans = s.wordBreak(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        input);
    EXPECT_TRUE(ans);

    input = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    ans = s.wordBreak(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        input);
    EXPECT_FALSE(ans);
}