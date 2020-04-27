//
// Created by Hywfred on 2020/4/6.
//
//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符
//示例 1：
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
//示例 2：
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
#ifndef LEETCODEINCPP_EDITDISTANCE_H
#define LEETCODEINCPP_EDITDISTANCE_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 动态规划
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        // dp[i][j] 代表从 word1 的前 i 个字符转换到 word2 的前 j 个字符所用的最少转换次数
        // i 和 j 从 1 开始
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        // 初始状态
        dp[0][0] = 0; // word1 0 --> word2 0 不需要转换
        // word1 0 --> word2 i: 插入 word2 第 i 个字符
        for (int i = 1; i <= len2; ++i) {
            dp[0][i] = i;
        }
        // word1 j --> word2 0 删除 word1 第 j 个字符
        for (int j = 1; j <= len1; ++j) {
            dp[j][0] = j;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // dp[i-1][j-1] 代表替换：将 word1 第 i 个字符替换为 word2 第 j 个字符
                    // dp[i-1][j] 代表删除：将 word1 第 i 个字符删除
                    // dp[i][j-1] 代表插入：word2 第 j 个字符插入到 word1 末端
                    // 三种情况取最小值 + 1。
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) +  1;
                }
            }
        }
        return dp[len1][len2];
    }
};
#endif //LEETCODEINCPP_EDITDISTANCE_H
