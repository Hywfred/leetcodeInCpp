/**
 * https://leetcode-cn.com/problems/re-space-lcci/
 */
#include <algorithm>
#include <unordered_set>

#include "daily.h"

using namespace std;

struct Trie {
    Trie() : childs(26, nullptr), end(false) {}
    vector<Trie *> childs;
    bool end;
};
/**
 * 生成字典树
 */
Trie *build_tree(vector<string> &dic) {
    Trie *root = new Trie;
    for (const auto &elem : dic) {
        Trie *node = root;
        for (auto c : elem) {
            auto idx = c - 'a';
            if (!node->childs[idx]) {
                auto tmp = new Trie;
                node->childs[idx] = tmp;
            }
            node = node->childs[idx];
        }
        node->end = true;
    }
    return root;
}
/**
 * 如果有字典树，从后往前遍历比较方便，这是由字典树的特性决定的
 */
int Solution::respace(vector<string> &dictionary, string sentence) {
    // 生成字典树
    auto root = build_tree(dictionary);
    int len = sentence.length();
    // dp[i] 代表从 i 个字符开始到字符串末尾，未识别的最少字符数
    vector<int> dp(len + 1);
    Trie *node;
    for (int i = len - 1; i >= 0; --i) {
        node = root;
        dp[i] = len - i;  // 初始默认全部不在字典中
        for (int j = i; j != len; ++j) {
            auto idx = sentence[j] - 'a';
            // 以该字符开头的单词不存在
            if (!node->childs[idx]) {
                dp[i] = min(dp[i], j - i + 1 + dp[j + 1]);
                break;
            }
            // 找到单词
            if (node->childs[idx]->end)
                dp[i] = min(dp[i], dp[j + 1]);
            else
                dp[i] = min(dp[i], j - i + 1 + dp[j + 1]);
            node = node->childs[idx];
        }
    }
    delete root;
    return dp[0];
}

/**
 * https://leetcode-cn.com/problems/re-space-lcci/solution/cong-bao-li-ru-shou-you-hua-yi-ji-triezi-dian-shu-/
 * 效率比较低
 */
// int Solution::respace(vector<string> &dictionary, string sentence) {
//     // 先将字典中的点此放入集合
//     unordered_set<string> words;
//     for (auto &elem : dictionary) { words.insert(std::move(elem)); }
//     int len = sentence.length();
//     // dp[i] 代表前 i 个字符中未识别的最少字符
//     vector<int> dp(len + 1);
//     for (int i = 1; i <= len; ++i) {
//         dp[i] = dp[i - 1] + 1;         // 先假设 当前字符没有在字典中匹配
//         for (int j = 0; j < i; ++j) {  // 遍历之前的字符，并判断该字符到i构成的子串是否在字典中
//             // 如果在字典中，因为可能有多个，所以选最小的那个
//             auto str = sentence.substr(j, i - j);
//             if (words.count(str)) dp[i] = dp[i] > dp[j] ? dp[j] : dp[i];
//         }
//     }
//     return dp[len];
// }