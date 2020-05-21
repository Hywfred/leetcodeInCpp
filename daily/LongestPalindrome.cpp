/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
 */
#include "daily.h"

using namespace std;

bool isPalindrome(const string &s, decltype(s.size()) first, decltype(s.size()) last) {
    while (first < last) {
        if (s[first] != s[last]) return false;
        ++first, --last;
    }
    return true;
}
/**
 * 动态规划：s[i][j] 代表子串 [i, j] 是否为回文字符串
 */
string Solution::longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    int beg, len = 1;
    vector<vector<bool>> isPldrm(s.size(), vector<bool>(s.size(), true));
    for (decltype(s.size()) j = 1; j != s.size(); ++j)
        for (decltype(s.size()) i = 0; i < j; ++i) {
            if (s.at(i) != s.at(j)) {
                isPldrm[i][j] = false;
            } else {
                if (j - i >= 3) isPldrm[i][j] = isPldrm[i + 1][j - 1];
            }
            if (isPldrm[i][j] && j - i + 1 > len) {
                beg = i;
                len = j - i + 1;
            }
        }
    return s.substr(beg, len);
}

/**
 * 暴力法，一开始是超时的，优化之后可以通过，但是效率不高。
 * 优化方式：
 * 1. 判断时，只判断长度大于当前回文子串长度的情形
 * 2. 判断回文时，不要真的构建子串，只传递索引进行判断
 */
string longestPalindromeViolence(string s) {
    if (s.length() <= 1) return s;
    string ans;
    for (decltype(s.size()) i = 0; i != s.size() - 1; ++i)
        for (decltype(s.size()) j = 1; j <= s.size() - i; ++j) {
            if (j > ans.size() && isPalindrome(s, i, i + j - 1)) ans = s.substr(i, j);
        }

    return ans;
}