/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。 
 */
#include <unordered_map>

#include "daily.h"

using namespace std;

int Solution::lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return s.length();
    unordered_map<char, int> visited;  // 存储当前无重复子串中每个字符的索引
    int ans = 0;                       // 存储结果
    auto beg = s.begin(), end = s.end();
    auto left = beg, right = beg;
    while (right != end) {
        while (right != end && visited.find(*right) == visited.end()) {
            visited[*right] = right - beg;  // 标记当前字符的绝对位置
            ++right;
        }
        // 先检查是否需要更新最大长度，如果需要则更新
        ans = right - left > ans ? right - left : ans;
        // 如果 right 到达字符串末尾
        if (right == end) break;
        // right 已经被放问过
        for (auto it = left; it < beg + visited[*right]; ++it) {
            visited.erase(*it);
        }
        left = beg + visited[*right] + 1;  // left 更新为 重复字符的下一个位置
        visited[*right] = right - beg;     // 更新重复字符的索引
        ++right;
    }
    return ans;
}