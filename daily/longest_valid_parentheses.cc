/**
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
 */
#include <stack>

#include "daily.h"

using namespace std;

int Solution::longestValidParentheses(string s) {
    if (s.empty()) return 0;
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            stk.push(i);
        else {
            stk.pop();
            if (stk.empty())
                stk.push(i);
            else
                ans = i - stk.top() > ans ? i - stk.top() : ans;
        }
    }
    return ans;
}