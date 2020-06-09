/**
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成
“z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
提示：
0 <= num < 2^31
 */
#include "daily.h"

using namespace std;

/**
 * 优化版本
 */
int Solution::translateNum(int num) {
    if (num < 10) return 1;
    if (num <= 25) return 2;
    if (num < 100) return 1;
    deque<int> nums;
    while (num) {
        nums.push_front(num % 10);
        num /= 10;
    }
    int pre = 1;
    int cur = nums[0] * 10 + nums[1] > 25 ? 1 : 2;
    int n = 0;
    for (int i = 2; i != nums.size(); ++i) {
        if (!nums[i - 1]) {
            pre = cur;
            continue;
        }
        n = nums[i - 1] * 10 + nums[i];
        int tmp = cur;
        cur = tmp + pre * (n > 25 ? 0 : 1);
        pre = tmp;
    }
    return cur;
}

/**
 * 动态规划
 */
// int Solution::translateNum(int num) {
//     if (num < 10) return 1;
//     if (num <= 25) return 2;
//     if (num < 100) return 1;
//     string num_str = to_string(num);
//     int len = num_str.length();
//     vector<int> dp(len);
//     dp[0] = 1;
//     dp[1] = (num_str[0] - '0') * 10 + (num_str[1] - '0') > 25 ? 1 : 2;
//     int n = 0;
//     for (int i = 2; i != len; ++i) {
//         if (num_str[i - 1] == '0') {
//             dp[i] = dp[i - 1];
//             continue;
//         }
//         n = (num_str[i - 1] - '0') * 10 + (num_str[i] - '0');
//         dp[i] = dp[i - 1] + dp[i - 2] * (n > 25 ? 0 : 1);
//     }
//     return dp[len - 1];
// }