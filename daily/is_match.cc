/**
 *给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a'
重复了一次。
示例 3:
输入: s = "ab" p = ".*"
输出: true 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
 */
#include "daily.h"

using namespace std;

/**
 * 思路：递归
 */
bool match(const string &s, const string &p, int si, int pi) {
    int lens = s.size(), lenp = p.size();
    if (si >= lens && pi >= lenp) return true;
    // 此处注意 当索引 si == lens 时，应当继续进行判断
    // 以防止 s 以遍历完，p 只剩 a* 类似情况
    if (si > lens || pi >= lenp) return false;
    // 1. 如果 pi 后面为 *
    if (pi + 1 < p.size() && p[pi + 1] == '*') {
        // 1.1 如果 s已遍历完 或者 si 和 pi 处字符相同 或者 pi 处字符为 .
        // 此时：继续向后匹配 s 或者越过当前模式 "p[pi]*" 向后匹配
        // 例如：s="aab" p="a*ab" 或 s="aaa" p="a*a"
        if (si == lens || s[si] == p[pi] || p[pi] == '.') return match(s, p, si + 1, pi) || match(s, p, si, pi + 2);
        // 1.2 如 si 和 pi 处字符不同 且 pi 处字符不为 .
        // 此时：直接越过模式 "p[pi]*" 向后匹配
        // 例如：s="aab" p="b*aab"
        else
            return match(s, p, si, pi + 2);
    } else {
        // 2. pi 后面不为 *
        // 此时：直接判断当前 si 和 pi 对应的字符是否相同
        // 例如：s="abc" p="bbc" 或 s="abc" p=".bc"
        if (si == lens) return false;
        if (s[si] == p[pi] || p[pi] == '.')
            return match(s, p, si + 1, pi + 1);
        else
            return false;
    }
}

bool Solution::isMatch(string s, string p) { return match(s, p, 0, 0); }