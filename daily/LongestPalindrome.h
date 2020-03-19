//
// Created by Hywfred on 2020/3/19.
//
//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//注意:
//假设字符串的长度不会超过 1010。
//示例 1:
//输入:
//"abccccdd"
//输出:
//7
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
#ifndef LEETCODEINCPP_LONGESTPALINDROME_H
#define LEETCODEINCPP_LONGESTPALINDROME_H

#include <string>
using  namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int len = s.size();
        if (len < 2) {
            return len;
        }
        for (int i = 1; i < len; ++i) {
            int l = i-1;
            int r = i;
            while (l >=0 && r < len && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r- l - 1 > ans) {
                ans = r - l - 1;
            }
            l = i - 1;
            r = i + 1;
            while (l >=0 && r < len && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r- l - 1 > ans) {
                ans = r - l - 1;
            }
        }
        return  ans;
    }
};
#endif //LEETCODEINCPP_LONGESTPALINDROME_H
