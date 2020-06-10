/**
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
输入: "aba"
输出: True
示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是 50000。
 */
#include "daily.h"

using namespace std;

/**
 * 优化版本
 */

bool isPalindrome_(const string &s, decltype(s.size()) first, decltype(s.size()) last) {
    if (first >= last) return true;
    while (first < last) {
        if (s.at(first) != s.at(last)) return false;
        ++first, --last;
    }
    return true;
}

bool Solution::validPalindrome(string s) {
    for (decltype(s.size()) i = 0, j = s.size() - 1; i < j; ++i, --j)
        if (s.at(i) != s.at(j)) return isPalindrome_(s, i + 1, j) || isPalindrome_(s, i, j - 1);
    return true;
}

/**
 * VERSION 2
 * 此方法可行 但是效率有点低
 */
bool isPalindrome(const string &s, string::iterator first, string::iterator last, int count) {
    if (first >= last) return true;
    if (*first != *last && count >= 1) return false;
    if (*first == *last)
        return isPalindrome(s, first + 1, last - 1, count);
    else if (*first != *(last - 1) && *(first + 1) != *last)
        return false;
    else
        return isPalindrome(s, first, last - 1, count + 1) || isPalindrome(s, first + 1, last, count + 1);
}

bool validPalindrome2(string s) { return isPalindrome(s, s.begin(), s.end() - 1, 0); }

/**
 * VERSION 1
 * wrong version
 * 找到第一个不同的字符串之后的判断有问题
 */
bool validPalindromeOld(string s) {
    if (s.length() < 3) return true;
    bool ans;
    auto first = s.cbegin(), last = s.cend() - 1;
    while (first < last && *first++ == *last--) {}
    // 本身是回文字符串
    if (*(first - 1) == *(last + 1)) return true;
    // 碰到不相同的字符
    ++last, --first;
    if (last - first <= 1) return true;  // 如果不同的字符相邻 此时可以删掉一个字符成为回文字符串 返回 true
    // 不同字符相隔多于 1 个距离
    if (*first == *(last - 1))
        --last;
    else if (*(first + 1) == *last)
        ++first;
    else
        return false;
    while (first < last) {
        if (*first != *last) return false;
        ++first, --last;
    }
    return true;
}
