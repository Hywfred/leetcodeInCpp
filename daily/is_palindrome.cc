/**
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false
 */
#include "daily.h"

using namespace std;

bool isalpha(char c) {
    if (c >= 'a' && c <= 'z') return true;
    if (c >= 'A' && c <= 'Z') return true;

    return false;
}
bool isnum(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

bool Solution::isPalindrome(string s) {
    if (s.empty()) return true;
    int len = s.length();
    int left = 0, right = len - 1;

    while (left < right) {
        // 如果不是字母或数字
        if (!isalpha(s[left]) && !isnum(s[left])) {
            ++left;
            continue;
        }
        if (!isalpha(s[right]) && !isnum(s[right])) {
            --right;
            continue;
        }
        // 如果相等
        if (isnum(s[left]) && isnum(s[right]) && s[left] == s[right]) {
            ++left, --right;
            continue;
        };
        if (isalpha(s[left]) && isalpha(s[right]) &&
            (s[left] - 'A' == s[right] - 'a' || s[left] - 'a' == s[right] - 'A' || s[left] == s[right])) {
            ++left, --right;
            continue;
        };
        // 不相等则直接退出
        return false;
    }
    return true;
}