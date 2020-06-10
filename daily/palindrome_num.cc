/**
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:
你能不将整数转为字符串来解决这个问题吗？
 */
#include "daily.h"

using namespace std;

/**
 * 最终思路
 * 类似于第一次尝试，不过不是将所有数字都翻转，而是翻转一半左右
 * 即当前数字 > 翻转数字时进行翻转
 * 翻转结束时，cur == reverse 或者 cur == reverse / 10 即为回文数
 * 如 121 翻转后为 1 和 12
 * 如 1221 翻转后为 12 和 12
 * 这样同时也可以避免溢出，还能少一个变量
 * 但是有一点需要注意就是，如果最后一位为0需要特别处理，因为1210这样的会
 * 被判断为回文数
 */
bool Solution::isPalindrome(int x) {
    if (x < 0 || (!(x % 10) && x)) return false;
    int reverse = 0;
    while (x > reverse) {
        reverse = reverse * 10 + (x % 10);
        x /= 10;
    }
    return x == reverse || x == reverse / 10;
}

/**
 * 其他思路：不用转换为字符串，可以使用数组来辅助解决
 */
// bool Solution::isPalindrome(int x) {
//     // 负数不是回文数
//     if (x < 0) return false;
//     vector<int> x_num;
//     while (x) {
//         x_num.push_back(x % 10);
//         x /= 10;
//     }
//     for (int i = 0, j = x_num.size() - 1; i < j; ++i, --j) {
//         if (x_num[i] != x_num[j]) return false;
//     }
//     return true;
// }

/**
 * 将整数转换为逆序，与原数一样即可
 * 注意：------------------------
 * int 逆序可能不是 int，所以需要更大的类型或者其他思路
 *
 * 由此题引发思考，操作 int 等类型时，一定要注意不要溢出
 * 也就是注意整型的范围。
 */
// bool Solution::isPalindrome(int x) {
//     if (x < 0) return false;
//     long long ans = 0;
//     long long old_x = x;
//     long long tmp = x;
//     while (tmp) {
//         ans = ans * 10 + (tmp % 10);
//         tmp /= 10;
//     }
//     return ans == old_x;
// }