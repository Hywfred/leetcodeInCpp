/**
 * https://leetcode-cn.com/problems/add-strings/
 * 给定两个字符串形式的非负整数 num1 和 num2 ，计算它们的和。
注意：
num1 和 num2 的长度都小于 5100.
num1 和 num2 都只包含数字 0-9.
num1 和 num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 */
#include "daily.h"

using namespace std;

string Solution::addStrings(string num1, string num2) {
    if (num1.empty()) return num2;
    if (num2.empty()) return num1;
    if (num1.size() < num2.size()) num1.swap(num2);
    int len1 = num1.size(), len2 = num2.size();
    int ten = '0' * 2 + 10;
    int carry = 0;
    int idx1 = len1 - 1, idx2 = len2 - 1;
    int sum;
    while (idx1 >= 0 && idx2 >= 0) {
        sum = num1[idx1] + num2[idx2] + carry;
        if (sum >= ten) {
            carry = 1;
            num1[idx1] = sum - '0' - 10;
            --idx1, --idx2;
            continue;
        }
        carry = 0;
        num1[idx1] = sum - '0';
        --idx1, --idx2;
    }
    while (carry && idx1 >= 0) {
        sum = num1[idx1] + carry;
        if (sum >= 10 + '0') {
            carry = 1;
            num1[idx1] = sum - 10;
            --idx1;
            continue;
        }
        carry = 0;
        num1[idx1] = sum;
    }
    return carry ? '1' + num1 : num1;
}