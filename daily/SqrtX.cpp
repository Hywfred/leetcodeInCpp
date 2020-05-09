/**
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
示例 1:
输入: 4
输出: 2
示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
 */
#include "daily.h"

/**
 * 使用牛顿法
 */
int Solution::mySqrt(int x) {
    if (!x) return x;
    double cur = 1;
    double pre = cur;
    while (true) {
        cur = (cur + x / cur) / 2;
        double abs = cur > pre ? cur - pre : pre - cur;
        if (abs < 1e-6) break;
        pre = cur;
    }
    return cur;
}