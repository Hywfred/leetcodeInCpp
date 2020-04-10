//
// Created by Hywfred on 2020/4/10.
//
//给定一个字符串，逐个翻转字符串中的每个单词。
//示例 1：
//输入: "the sky is blue"
//输出: "blue is sky the"
//示例 2：
//输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//示例 3：
//输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//说明：
//无空格字符构成一个单词。
//输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//进阶：
//请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
#ifndef LEETCODEINCPP_REVERSEWORDSINASTR_H
#define LEETCODEINCPP_REVERSEWORDSINASTR_H

#include <string>
using namespace std;
class Solution {
public:
    static string reverseWords(string s) {
        string ans;
        if (s.empty()) return ans;
        int len = s.size();
        int left, right = len;
        while (true) {
            // 寻找接下来第一个非空字符
            while (--right >= 0 && s[right] == ' ');
            if (right < 0) break;
            // 寻找接下来第一个空字符
            left = right;
            while (--left >= 0 && s[left] != ' ');
            // 此时 right 指向非空字符，left 指向 right 前面第一个空字符
            ans += s.substr(left + 1, right-left) + " ";
            if (left < 0) break;
            // 更新 right
            right = left;
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_REVERSEWORDSINASTR_H
