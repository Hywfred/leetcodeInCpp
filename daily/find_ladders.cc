/**
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord
的最短转换序列。转换需遵循如下规则： 每次转换只能改变一个字母。 转换过程中的中间单词必须是字典中的单词。 说明:
如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: []
解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
*/
#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include "daily.h"

using namespace std;

// 存储键字符串对应的下一个可选的字符串
// 该哈希表需要从两端同时进行构建，以节省时间
unordered_map<string, unordered_set<string>> next_map;
vector<vector<string>> ans;

void dfs(const string &begin, const string &end, vector<string> &seq) {
    if (begin == end) {
        ans.emplace_back(seq);
        return;
    }
    if (!next_map.count(begin)) return;
    for (const auto &next : next_map[begin]) {
        seq.push_back(next);
        dfs(next, end, seq);
        seq.pop_back();
    }
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    // 用哈希表存储单词列表，查询时间为 O(1)
    unordered_set<string> words(wordList.cbegin(), wordList.cend());
    // 如果单词列表中没有目标单词，直接返回
    if (!words.count(endWord)) return {};
    // first_half 存储从前向后开始寻找的字符串
    unordered_set<string> first_half{beginWord};
    // second_half 存储从后向前寻找的字符串
    unordered_set<string> second_half{endWord};
    // met 代表相遇 rvs 代表反向
    bool met = false, rvs = false;
    while (!first_half.empty()) {
        unordered_set<string> next_half;
        for (const auto &elem : first_half) {
            // 先将 words 中的 word 删除，避免下面查找的时候把 word 本身添加进去
            words.erase(elem);
        }
        for (const auto &word : first_half) {
            auto len = word.length();
            for (decltype(len) i = 0; i != len; ++i) {
                auto tmp = word;
                for (int j = 'a'; j <= 'z'; ++j) {
                    tmp[i] = j;
                    if (!words.count(tmp)) continue;
                    // 找到下一个，先判断前后查找是否相遇
                    if (second_half.count(tmp))
                        met = true;  // 相遇
                    else
                        next_half.emplace(tmp);
                    // 如果是方向查找，需要注意存储到字典时的键值顺序
                    rvs ? next_map[tmp].emplace(word) : next_map[word].emplace(tmp);
                }
            }
        }
        if (met) break;
        first_half = next_half;
        if (first_half.size() > second_half.size()) {
            swap(first_half, second_half);
            rvs = !rvs;
        }
    }
    vector<string> cur{beginWord};
    dfs(beginWord, endWord, cur);
    return ans;
}

/*
bool one_letter_differ(const string &s1, const string &s2) {
    bool ans = false;
    auto len = s1.size();
    decltype(len) count = 0;
    for (decltype(len) i = 0; i != len; ++i) {
        if (s1[i] != s2[i]) ++count;
        if (count > 1) return false;
    }
    return count ? true : false;
}

void find(const string &begin, const string &end, const vector<string> &words, vector<bool> &visited,
          vector<string> &cur, list<vector<string>> &ans) {
    auto len = words.size();
    for (decltype(len) i = 0; i != len; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            if (one_letter_differ(words[i], begin)) {
                cur.push_back(words[i]);
                // 如果满足条件
                if (words[i] == end) {
                    if (ans.empty())
                        ans.emplace_back(cur.cbegin(), cur.cend());
                    else if (cur.size() < ans.back().size()) {
                        ans.clear();
                        ans.emplace_back(cur.cbegin(), cur.cend());
                    } else if (cur.size() == ans.back().size())
                        ans.emplace_back(cur.cbegin(), cur.cend());
                    visited[i] = false;
                    cur.pop_back();
                    return;
                }
                // 继续寻找下一个
                find(words[i], end, words, visited, cur, ans);
                // 返回之后，恢复状态
                visited[i] = false;
                cur.pop_back();
            } else {
                visited[i] = false;
            }
        }
    }
    // 不满足条件 已经找完了或者不能通过改变一个字符完成
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string> &wordList) {
    if (wordList.empty()) return {};
    if (find(wordList.cbegin(), wordList.cend(), endWord) == wordList.cend()) return {};
    vector<bool> visited(wordList.size());
    list<vector<string>> ans;
    vector<string> cur{beginWord};
    find(beginWord, endWord, wordList, visited, cur, ans);
    // 返回最短序列
    vector<vector<string>> res(ans.cbegin(), ans.cend());
    return res;
}
*/

/*
//用记忆来培养思维，而不是单纯记忆。
//讲东西时先抛开代码讲整体思路，然后再具体到代码讲细节。
//双端BFS构建整颗最短树，DFS找最短树中beginWord到endWord的路径，因为最短树层数就那么多，所以找到的路径一定是最短的。
//当beginSet中的一个单词在endSet中出现时，说明双端搜索相遇了。
//用双端搜索而不是单端，是因为双端更省时。
class Solution1 {
  private:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> map;
    //用unordered_map是因为查找key的时间复杂度O(1),找到了key，对应的value就是树的下一层了。(vector<vector<string>>的查找就太慢了)，用map的key来存储原string,用value来存储原string所有的下一层string(wordSet中所有的只与原string相差一个字符的word)
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        // BFS把找最短序列过程中的每一层的erase后的wordSet中的word们都统计出，包括相遇的那层的word们。然后用dfs去搜索
        //最短序列，因为只统计到相遇那一层，层数就那么多，所以dfs找到的序列层数一定是那么多，所以一定是最短序列。
        unordered_set<string> wordSet{wordList.begin(), wordList.end()};
        if (!wordSet.count(endWord)) return res;
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int flag1 = 0, flag2 = 0;  // flag1标记是否已经双端搜索相遇了
        while (!beginSet.empty()) {
            unordered_set<string> next;
            for (string word : beginSet) {  //单独建个循环统一删除
                wordSet.erase(word);
            }
            for (string word : beginSet) {
                for (int w = 0; w < word.size(); ++w) {
                    string tmp = word;
                    for (int i = 'a'; i <= 'z'; ++i) {
                        tmp[w] = i;
                        if (!wordSet.count(tmp)) continue;
                        if (!endSet.count(tmp))
                            next.emplace(tmp);
                        else
                            flag1 = 1;  // flag1 = 1，双端set搜索相遇了，在添加完这一整层的word后退出循环。
                        flag2 ? map[tmp].emplace_back(word) : map[word].emplace_back(tmp);
                    }
                }
            }
            if (flag1) break;
            beginSet = next;
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
                flag2 = !flag2;  //搜索方向取反，所以flag2标志也要取反，这样子构建的树是从上到下顺序构造的。
            }
        }
        vector<string> vec{beginWord};
        dfs(vec, beginWord, endWord);
        return res;
    }

    void dfs(vector<string> &vec, string beginWord, string endWord) {
        if (beginWord == endWord) {
            res.push_back(vec);
            return;
        }
        if (!map.count(beginWord)) return;
        //对于BFS出的哈希表，单层交给迭代，整棵树交给递归
        for (auto &temp : map[beginWord]) {
            vec.emplace_back(temp);
            dfs(vec, temp, endWord);
            vec.pop_back();
        }
    }
};
*/