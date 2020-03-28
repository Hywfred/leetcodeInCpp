//
// Created by Hywfred on 2020/3/28.
//
//给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
//例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
//对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
//那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
//示例：
//输入: words = ["time", "me", "bell"]
//输出: 10
//说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
//提示：
//1 <= words.length <= 2000
//1 <= words[i].length <= 7
//每个单词都是小写字母 。
#ifndef LEETCODEINCPP_SHORTENCODINGOFWORDS_H
#define LEETCODEINCPP_SHORTENCODINGOFWORDS_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
     * 改进版本
     */
    static bool compare(const string& s1, const string& s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        int min = 0;
        if (l1 < l2) min = l1; else min = l2;
        for (int i = 0; i < min; ++i) {
            if (s1[l1 - 1 - i] == s2[l2 - 1 - i]) continue;
            else return s1[l1 - 1 - i] < s2[l2 - 1 - i];
        }
        return l1 < l2;
    }
    static bool endWith(const string& s1, const string& s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        int min = 0;
        if (l1 < l2) min = l1; else min = l2;
        for (int i = 0; i < min; ++i) {
            if (s1[l1 - 1 - i] != s2[l2 - 1 -i]) {
                return false;
            }
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int len = words.size();
        int i = 0;
        int ans = 0;
        while (i + 1 < len) {
            if (endWith(words[i], words[i + 1])) {
                ++i;
                continue;
            }
            else {
                ans += words[i].size() + 1;
                ++i;
            }
        }
        ans += words[len-1].size()+1;
        return ans;
    }
    /*
     * 超时版本
     */
    static bool cmd(string a, string b) {
        return a.size() > b.size();
    }
    int minimumLengthEncodingTimeout(vector<string>& words) {
        sort(words.begin(), words.end(), cmd);
        int ans = words[0].size() + 1;
        int wLen = words.size();
        for (int i = 1; i < wLen; ++i) {
            int iLen = words[i].size();
            bool contains = false;
            for (int j = 0; j < i; ++j) {
                if (words[j].substr(words[j].size() - iLen) == words[i]) {
                    contains = true;
                    break;
                }
            }
            if (!contains) {
                ans += iLen + 1;
            }
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_SHORTENCODINGOFWORDS_H
