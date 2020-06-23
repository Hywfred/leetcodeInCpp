/**
 *你有两个字符串，即 pattern 和 value。 pattern 字符串由字母 "a" 和 "b" 组成，用于描述字符串中的模式。例如，字符串
"catcatgocatgo" 匹配模式 "aabab"（其中 "cat" 是 "a"，"go" 是 "b"），该字符串也匹配像 "a"、"ab" 和 "b"
这样的模式。但需注意 "a" 和 "b" 不能同时表示相同的字符串。编写一个方法判断 value 字符串是否匹配 pattern 字符串。
示例 1：
输入： pattern = "abba", value = "dogcatcatdog"
输出： true
示例 2：
输入： pattern = "abba", value = "dogcatcatfish"
输出： false
示例 3：
输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false
示例 4：
输入：pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则
提示：
 0 <= len(pattern) <= 1000
 0 <= len(value) <= 1000
 你可以假设 pattern 只包含字母 "a" 和 "b"，value 仅包含小写字母。
 */
#include "daily.h"

using namespace std;

int cnt[2];

bool helper(string value, int k) {  // pattern不为空，value不为空. 判断是否可以k次切分value
    int m = value.size();
    if (m % k != 0) return false;
    int len = m / k;
    for (int i = len; i < m; i += len)
        if (value.substr(i, len) != value.substr(0, len)) return false;
    return true;
}

bool check(string pattern, string value, int len_a, int len_b) {
    string ps[2] = {"", ""};                           // a, b匹配的字符串
    for (int i = 0, j = 0; i < pattern.size(); i++) {  // i, j指针都是恰当长度的
        if (pattern[i] == 'a') {
            if (ps[0] == "")
                ps[0] = value.substr(j, len_a);
            else if (value.substr(j, len_a) != ps[0])
                return false;
            j += len_a;
        } else if (pattern[i] == 'b') {
            if (ps[1] == "")
                ps[1] = value.substr(j, len_b);
            else if (value.substr(j, len_b) != ps[1])
                return false;
            j += len_b;
        }
    }
    return ps[0] != ps[1];  // a,b所匹配的字符串不能相同
}

bool patternMatching(string pattern, string value) {
    // 分情况讨论
    // 1. pattern为空
    if (pattern.empty()) return value.empty();
    // 2. pattern不为空
    // 2.1 value为空, 判断pattern是否只由一个字母组成
    if (value.empty()) {
        int i = 0;
        while (i < pattern.size() && pattern[i] == pattern[0]) i++;
        return i == pattern.size();
    }
    // 2.2 pattern不为空，value不为空
    int n = pattern.size(), m = value.size();
    //   预处理统计a, b字母个数cnt[0], cnt[1]
    cnt[0] = cnt[1] = 0;
    for (auto x : pattern) cnt[x - 'a']++;
    //   判断cnt[0], cnt[1]是否有为0的情况
    if (!cnt[0])
        return helper(value, cnt[1]);
    else if (!cnt[1])
        return helper(value, cnt[0]);

    //  2.2.1 假设使得a,b其中之一为空, 即次数为0
    if (helper(value, cnt[0])) return true;
    if (helper(value, cnt[1])) return true;

    // 2.2.2 a,b都不为空; 枚举a, b匹配的长度，使得a * len_a + b * len_b = m; len_a唯一确定len_b，只需枚举len_a
    for (int len_a = 1; len_a * cnt[0] <= m - cnt[1]; len_a++) {
        if ((m - len_a * cnt[0]) % cnt[1] != 0) continue;
        int len_b = (m - len_a * cnt[0]) / cnt[1];
        if (check(pattern, value, len_a, len_b)) return true;
    }
    return false;
}

// bool is_match(const string &p, const string &v, int len_a, int len_b) {
//     bool first_a = true, first_b = true;
//     int numa = 0, numb = 0;
//     string a, b;
//     for (int i = 0; i < p.size(); ++i) {
//         if (p[i] == 'a') {
//             if (first_a) {
//                 a = v.substr(numa * len_a + numb * len_b, len_a);
//                 first_a = false;
//                 ++numa;
//             } else {
//                 for (int j = 0; j < len_a; ++j) {
//                     if (a[j] != v[numa * len_a + numb * len_b + j]) return false;
//                 }
//                 ++numa;
//             }
//         }
//         if (p[i] == 'b') {
//             if (first_b) {
//                 b = v.substr(numa * len_a + numb * len_b, len_b);
//                 first_b = false;
//                 ++numb;
//             } else {
//                 for (int j = 0; j < len_b; ++j) {
//                     if (b[j] != v[numa * len_a + numb * len_b + j]) return false;
//                 }
//                 ++numb;
//             }
//         }
//         if (!first_a && !first_b && a == b) return false;
//     }
//     return true;
// }
// // int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// bool Solution::patternMatching(string pattern, string value) {
//     if (pattern.empty() && value.empty()) return true;
//     if (pattern.empty()) return false;
//     // pattern 和 value 的长度
//     int len_p = pattern.length();
//     int len_v = value.length();
//     //获取 a 和 b 的数量
//     int num_a = 0, num_b = 0;
//     for (auto &c : pattern) {
//         if (c == 'a') ++num_a;
//         if (c == 'b') ++num_b;
//     }
//     if (num_a && num_b && value.empty()) return false;
//     if (!num_a) return len_v > num_b && is_match(string(num_b, 'b'), value, 0, len_v / num_b);
//     if (!num_b) return len_v > num_a && is_match(string(num_a, 'a'), value, len_v / num_a, 0);
//     // 1. a b 均不为空
//     // i 代表 a 的长度
//     for (int i = 1; i <= (len_v - num_b) / num_a; ++i) {
//         // 当value的长度减去a的长度后，剩余长度不能被 num_b 整除，则不能匹配
//         if ((len_v - num_a * i) % num_b != 0) continue;
//         // 可以整除时，则判断是否匹配
//         int len_b = (len_v - i * num_a) / num_b;
//         if (is_match(pattern, value, i, len_b)) { return true; }
//     }
//     // 2. a 为空，只有 len_v 能被 num_b 整除时才有可能匹配
//     if (len_v % num_b == 0) {
//         if (is_match(string(num_b, 'b'), value, 0, len_v / num_b)) return true;
//     }
//     // 3. b 为空，只有 len_v 能被 num_a 整除时才有可能匹配
//     if (len_v % num_a == 0) {
//         if (is_match(string(num_a, 'a'), value, len_v / num_a, 0)) return true;
//     }
//     return false;
// }