/**
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句（A?B:C）。
示例 1：
输入: n = 3
输出: 6
示例 2：
输入: n = 9
输出: 45
限制：
1 <= n <= 10000
 */
#include "daily.h"

using namespace std;

/**
 * 数学公式 但是违背题意了。
 */
int Solution::sumNums2(int n) { return n * (n + 1) / 2; }

/**
 * 还在考虑使用递归，但是如何退出递归是关键
 * 下面是参考题解的解法，很巧妙，利用逻辑运算符的短路运算作为递归运算结束的条件
 * 同时加深对递归的理解，类比于树的中序遍历、后序遍历。
 */

int sum_ans = 0;

int Solution::sumNums1(int n) {
    n > 1 && sumNums1(n - 1);
    sum_ans += n;
    return sum_ans;
}

/**
 * 继续优化理解递归
 * 每次返回 1-i 的和
 * 题目的关键在于如何停止递归
 */
int Solution::sumNums(int n) {
    n > 1 && (n += sumNums(n - 1));
    return n;
}