/**
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u'
，在子字符串中都恰好出现了偶数次。
示例 1： 输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor"，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
示例 2： 输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc"
，其中包含 2 个 e 。
示例 3： 输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc"
本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
提示： 1 <= s.length <= 5 x 10^5 s 只包含小写英文字母。
 */
#include <unordered_set>

#include "daily.h"

using namespace std;

/**
 * 前缀和 + 状态压缩
 */
int Solution::findTheLongestSubstring(std::string s) {
    int ans = 0;
    vector<unsigned> dict(1 << 5, 1 << 5);
    unsigned status = 0;  // 当前状态
    dict[status] = -1;
    for (decltype(status) idx = 0; idx != s.size(); ++idx) {
        // 当出现元音时更新状态
        switch (s.at(idx)) {
            case 'a':
                status ^= 1;
                break;
            case 'e':
                status ^= 1 << 1;
                break;
            case 'i':
                status ^= 1 << 2;
                break;
            case 'o':
                status ^= 1 << 3;
                break;
            case 'u':
                status ^= 1 << 4;
                break;
        }
        // status 第一次出现
        if (dict[status] == 1 << 5)
            dict[status] = idx;
        else
            ans = ans > idx - dict[status] ? ans : idx - dict[status];
    }
    return ans;
}