/**
 * https://leetcode-cn.com/problems/palindrome-pairs/
给定一组唯一的单词， 找出所有不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
示例 1:
输入: ["abcd","dcba","lls","s","sssll"]
输出: [[0,1],[1,0],[3,2],[2,4]]
解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
示例 2:
输入: ["bat","tab","cat"]
输出: [[0,1],[1,0]]
解释: 可拼接成的回文串为 ["battab","tabbat"]
 */
#include <unordered_map>

#include "daily.h"

using namespace std;
// 错误版本
// string reverse(string s, bool last_excluded = false) {
//     if (s.empty()) return s;
//     int l = 0, r;
//     if (last_excluded) s.pop_back();
//     r = s.size() - 1;
//     while (l < r) swap(s[l++], s[r--]);
//     return s;
// }

// bool is_palindrome(string s) {
//     int l = 0, r = s.size() - 1;
//     while (l < r) {
//         if (s[l++] != s[r--]) return false;
//     }
//     return true;
// }

// vector<vector<int>> Solution::palindromePairs(vector<string> &words) {
//     vector<vector<int>> ans;
//     unordered_map<string, int> maps;
//     for (int i = 0; i < words.size(); ++i) maps.insert({words[i], i});
//     for (auto &str : words) {
//         string rvs = reverse(str);
//         string rvs_last_excluded = reverse(str, true);
//         if (maps.count(rvs)) ans.push_back({maps[str], maps[rvs]});
//         if (maps.count(rvs_last_excluded)) ans.push_back({maps[str], maps[rvs_last_excluded]});
//     }
//     return ans;
// }

/**
 * 下面的 brute force 版本超时
 */
// bool is_palindrome(string s) {
//     int l = 0, r = s.size() - 1;
//     while (l < r) {
//         if (s[l++] != s[r--]) return false;
//     }
//     return true;
// }

// vector<vector<int>> palindromePairs(vector<string> &words) {
//     vector<vector<int>> ans;
//     for (int i = 0; i < words.size(); ++i) {
//         for (int j = 0; j < words.size(); ++j) {
//             if (i != j) {
//                 if (is_palindrome(words[i] + words[j])) ans.push_back({i, j});
//             }
//         }
//     }
//     return ans;
// }
