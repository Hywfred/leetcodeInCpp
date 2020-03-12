//
// Created by Hywfred on 2020/3/12.
//
// 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
//返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
//
//示例 1：
//输入：str1 = "ABCABC", str2 = "ABC"
//输出："ABC"

//示例 2：
//输入：str1 = "ABABAB", str2 = "ABAB"
//输出："AB"

//示例 3：
//输入：str1 = "LEET", str2 = "CODE"
//输出：""
// 
//提示：
//1 <= str1.length <= 1000
//1 <= str2.length <= 1000
//str1[i] 和 str2[i] 为大写英文字母
#ifndef LEETCODEINCPP_GREATESTCOMMONDIVISOR_H
#define LEETCODEINCPP_GREATESTCOMMONDIVISOR_H

#include <string>
using  namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 == str2) {
            return str1;
        }
        string longer, shorter;
        if (str1.size() > str2.size()) {
            longer = str1;
            shorter = str2;
        } else {
            longer = str2;
            shorter = str1;
        }
        int i;
        for (i = 0; i < shorter.size(); ++i) {
            if (longer[i] != shorter[i]) {
                return "";
            }
        }
        return gcdOfStrings(shorter, longer.substr(i));
    }
};

#endif //LEETCODEINCPP_GREATESTCOMMONDIVISOR_H
