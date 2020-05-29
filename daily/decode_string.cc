/**
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 */
#include <cctype>
#include <sstream>

#include "daily.h"

using namespace std;

int s2i(const string &s) {
    int ans = 0;
    for (auto beg = s.cbegin(); beg != s.cend(); ++beg) { ans = ans * 10 + (*beg - '0'); }
    return ans;
}

/**
 * s 是 3[encoded_str] 形式
 */
// string helper(const string &s, string::iterator first, decltype(first) last) {}

string Solution::decodeString(string s) {
    ostringstream os;
    int count = 0;
    decltype(s.cbegin()) num_beg = s.cend();
    decltype(num_beg) encoded_beg = s.cend();
    for (auto beg = s.cbegin(); beg != s.cend();) {
        if (isalpha(*beg)) {
            os << *beg;
            ++beg;
            continue;
        }
        // 此处 beg 指向的是数字
        num_beg = beg;
        while (isdigit(*++beg))
            ;
        count = s2i(string(num_beg, beg));
        // 此处 beg 指向 [，需要找到与之匹配的 ]
        encoded_beg = beg + 1;
        int match = 1;
        while (match > 0) {
            ++beg;
            if (*beg == '[') ++match;
            if (*beg == ']') --match;
        }
        // 此处 beg 指向匹配的 ]，
        // 递归调用对 encoded_string 的处理
        for (int i = 0; i != count; ++i) os << decodeString(string(encoded_beg, beg));
        // 当前指向 ]，向后移动一个字符
        ++beg;
    }
    return os.str();
}