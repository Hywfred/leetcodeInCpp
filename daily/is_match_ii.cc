/**
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:
输入:
s = "acdcb"
p = "a*c?b"
输出: false
 */
#include <algorithm>

#include "daily.h"

using namespace std;

bool Solution::isMatchII(string s, string p) {
    // 优化一：多个 * 合为 1 个
    string newp;
    for (auto c : p) {
        if (!newp.empty() && newp.back() == '*' && c == '*')
            continue;
        else
            newp += c;
    }
    int slen = s.size();
    int plen = newp.size();
    // dp[i][j] 代表 以第 i 个字符结尾的 s 子串和以第 j 个字符结尾的 p 子串是否匹配
    // i 和 j 从 1 开始
    vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
    dp[0][0] = true;
    dp[0][1] = newp[0] == '*' ? true : false;
    for (int i = 1; i <= slen; ++i) {
        for (int j = 1; j <= plen; ++j) {
            if (newp[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else {
                if (newp[j - 1] == '?' || s[i - 1] == newp[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }
    }
    return dp[slen][plen];
}

/**
 * 思路：递归，超时，优化后还是超时。考虑动态规划
 */

// bool match(string &s, string &p, int si, int pi) {
//     // s p 均为空 返回 true
//     if (si >= s.size() && pi >= p.size()) return true;
//     // p 为空 s 不为空 返回 false
//     if (pi >= p.size()) return false;
//     // p 不为空 s 为空
//     if (si >= s.size()) {
//         for (int i = pi; i < p.size(); ++i) {
//             if (p[i] != '*') return false;
//         }
//         return true;
//     }
//     // s p 均不为空
//     if (p[pi] == '*')
//         return match(s, p, si + 1, pi) || match(s, p, si, pi + 1);
//     else {
//         if (p[pi] == '?') {
//             return match(s, p, si + 1, pi + 1);
//         } else {
//             if (s[si] == p[pi]) {
//                 return match(s, p, si + 1, pi + 1);
//             } else {
//                 return false;
//             }
//         }
//     }
// }

// bool Solution::isMatchII(string s, string p) {
//     // "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b" 超时
//     // "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
//     //   "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*" 超时
//     // 优化一：多个 * 合为 1 个
//     string newp;
//     for (auto c : p) {
//         if (!newp.empty() && newp.back() == '*' && c == '*')
//             continue;
//         else
//             newp += c;
//     }
//     return match(s, newp, 0, 0);
// }