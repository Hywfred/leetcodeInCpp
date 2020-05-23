/**
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
 */
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include "daily.h"

using namespace std;

/**
 * 滑动窗口：先移动右边界满足条件，然后移动左边界，在满足条件的情况下
 * 更新结果。然后刚好不满足条件，继续移动右边界。
 */
string Solution::minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) return "";
    unordered_map<char, size_t> wants, occurs;
    // 记录 t 中出现的字符个数
    for (const auto &c : t) { ++wants[c]; }
    // left, right 代表滑动窗口
    auto left = s.cbegin(), right = left;
    size_t count = 0;
    size_t first = 0, max_len = s.size() + 1;
    while (right != s.cend()) {
        if (wants.find(*right) != wants.end()) {
            ++occurs[*right];
            if (occurs[*right] == wants[*right]) ++count;
        }
        // 如果满足结果就一直缩小窗口，更新结果
        while (count == wants.size()) {
            // 首先更新结果
            if (right - left + 1 < max_len) {
                first = left - s.cbegin();
                max_len = right - left + 1;
            }
            if (wants.find(*left) != wants.end()) {
                if (wants[*left] == occurs[*left]) --count;
                --occurs[*left];
            }
            ++left;
        }
        ++right;
    }
    return max_len == s.size() + 1 ? "" : s.substr(first, max_len);
}