//
// Created by Hywfred on 2020/4/9.
//
//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//例如，给出 n = 3，生成结果为：
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
//]
#ifndef LEETCODEINCPP_GENERATEPARENTHESES_H
#define LEETCODEINCPP_GENERATEPARENTHESES_H

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (!n) return ans;
        int total = n * 2;
        int lNum = 0;
        append(total, n, lNum, "", ans);
        return ans;
    }
    void append(int n, const int &lNumTotal, int lNum, string cur, vector<string> &ans) {
        // 生成完毕则退出
        if (n <= 0) {
            ans.push_back(cur);
            return;
        }
        // 生成
        int len = cur.size();
        int rNum = len - lNum;
        if (lNum < lNumTotal) { // 只有左括号小于最大数量，就可以放置
            append(n-1, lNumTotal, lNum+1, cur + "(", ans);

        }
        if (rNum < lNum) { // 只有右括号数量小于左括号，才可以放置
            append(n-1, lNumTotal, lNum, cur + ")", ans);
        }
    }
};
#endif //LEETCODEINCPP_GENERATEPARENTHESES_H
