/**
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
 */
#include <unordered_map>
#include <unordered_set>

#include "daily.h"

using namespace std;

/**
 * 从 str 的 start 下标开始匹配模式 p
 * 看是否 p 可以被完全匹配
 * 例如 str = "helloword"
 * 如果 p = "hello" 可以被匹配
 * 如果 p = "ha.." 则不能匹配
 */
int match(const string &p, const string &str, int start) {
    if (str.size() - start < p.size()) return -1;
    int j = 0;
    while (start < str.size() && j < p.size()) {
        if (p[j] != str[start]) return -1;
        ++start, ++j;
    }
    return j >= p.size() && start <= str.size() ? start : -1;
}

bool recurse_match(const string &s, unordered_map<char, unordered_set<string>> &dict, int start, vector<int> &visited) {
    // 先判断当前 start 是否遍历过
    if (visited[start] != -1) return visited[start];
    if (start == s.size()) return true;
    auto key = s[start];  // 当前匹配的单词首字母
    if (!dict.count(key)) return false;
    for (const auto &word : dict[key]) {
        int tmp = match(word, s, start);
        if (tmp != -1 && recurse_match(s, dict, tmp, visited)) {
            visited[start] = 1;
            return true;
        } else {
            continue;
        }
    }
    // 当前首字母开头的所有单词都没有匹配
    visited[start] = 0;
    return false;
}

bool Solution::wordBreak(string s, vector<string> &wordDict) {
    unordered_map<char, unordered_set<string>> dict;
    // 将 wordDict 装入字典
    for (const auto &word : wordDict) dict[word[0]].insert(word);
    // 增加记忆数组
    vector<int> visited(s.size() + 1, -1);
    // 判断
    return recurse_match(s, dict, 0, visited);
}