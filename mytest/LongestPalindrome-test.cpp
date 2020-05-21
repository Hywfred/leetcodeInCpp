// #include "LongestPalindrome.cpp"
#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, longest_palindrome) {
    // auto ans = longestPalindromeViolence("babad");
    // EXPECT_EQ(ans, "bab");

    // ans = longestPalindromeViolence("cbbd");
    // EXPECT_EQ(ans, "bb");

    // ans = longestPalindromeViolence("abcdef");
    // EXPECT_EQ(ans, "a");
    Solution s;
    auto ans = s.longestPalindrome("babad");
    EXPECT_EQ(ans, "bab");

    ans = s.longestPalindrome("cbbd");
    EXPECT_EQ(ans, "bb");

    ans = s.longestPalindrome("abcdef");
    EXPECT_EQ(ans, "a");

    ans = s.longestPalindrome(
        "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxys"
        "ctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhv"
        "pqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrs"
        "wpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtd"
        "svehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcp"
        "ogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfe"
        "ejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspej"
        "enpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip");
    cout << ans << endl;
}
