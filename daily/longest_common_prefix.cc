/**
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"
示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:
所有输入只包含小写字母 a-z 。
 */
#include <limits>

#include "daily.h"

using namespace std;

string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return string();
    int len = numeric_limits<int>::max();
    for (int i = 0; i != strs.size(); ++i)
        if (strs[i].size() < len) len = strs[i].size();
    string ans;
    int idx = 0;
    bool found = true;
    while (true) {
        for (int i = 1; i != strs.size(); ++i) {
            if (strs[i][idx] == strs[0][idx])
                continue;
            else
                return strs[0].substr(0, idx);
        }
        if (idx >= len - 1) break;
        ++idx;
    }
    return strs[0].substr(0, idx + 1);
}