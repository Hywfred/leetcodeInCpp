/**
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 True ；不是，则返回 False 。
示例：
输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
 */
#include "daily.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int getNext(int n) {
    int sum = 0;
    while (n) {
        int bit = n % 10;
        sum += bit * bit;
        n = n / 10;
    }
    return sum;
}

/**
 * 本次优化利用 快慢指针；类似于寻找链表的环。
 * 参考 https://www.zhihu.com/question/23208893 李康的回答
 */
bool Solution::isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = getNext(slow);
        // cout << "slow: \t" << slow << endl;
        fast = getNext(getNext(fast));
        // cout << "fast: \t" << fast << endl;
    } while (slow != fast);
    // cout << "Meet! \t\t" << fast << endl;
    return slow == 1 ? true : false;
}

/** 
 * 第一次的猜想验证成功，但是未经证明
 * 本次优化“查找时候出现过”的算法，通过map实现搜索时间复杂度为 O(1)
 */
bool isHappy2(int n) {
    unordered_map<int, int> Cnter;
    bool ans;
    Cnter[n] = 1;
    while (true) {
        int sum = 0;
        while (n) {
            int remainder = n % 10;
            n = n / 10;
            sum += remainder * remainder;
        }
        // 判断 sum 是否为 1
        if (sum == 1) {
            ans = true;
            break;
        }
        // 判断 sum 是否出现过
        if (Cnter[sum]) {
            ans = false;
            break;
        } else {
            Cnter[sum] = 1;
            n = sum;
        }
    }
    return ans;
}

/** 
 * 猜想如果得不到 1 的情况会有重复数字出现
 */
bool isHappy1(int n) {
    vector<int> appeared;
    bool ans;
    appeared.push_back(n);
    while (true) {
        int sum = 0;
        while (n) {
            int remainder = n % 10;
            n = n / 10;
            sum += remainder * remainder;
        }
        // 判断 sum 是否为 1
        if (sum == 1) {
            ans = true;
            break;
        }
        // 判断 sum 是否出现过
        if (find(appeared.begin(), appeared.end(), sum) != appeared.end()) {
            ans = false;
            break;
        } else {
            appeared.push_back(sum);
            n = sum;
        }
    }
    return ans;
}