/**
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。
示例 1:
输入: a = "11", b = "1"
输出: "100"
示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
 */
#include "daily.h"

using namespace std;

string Solution::addBinary(string a, string b) {
    // a 总是持有大的那一个
    if (a.size() < b.size()) a.swap(b);
    int i = a.size() - 1, j = b.size() - 1;
    string ans;
    int carry = 0;
    char dic[4]{'0', '1', '0', '1'};
    auto calc = [&](int sum) {
        ans.push_back(dic[sum]);
        if (sum >= 2)
            carry = 1;
        else
            carry = 0;
    };
    while (i >= 0 && j >= 0) {
        int sum = a[i] - '0' + b[j] - '0' + carry;
        calc(sum);
        --i, --j;
    }
    while (i >= 0) {
        int sum = a[i] - '0' + carry;
        calc(sum);
        --i, --j;
    }
    if (carry) ans.push_back('1');
    return string(ans.rbegin(), ans.rend());
}