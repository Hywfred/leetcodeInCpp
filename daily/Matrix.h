//
// Created by Hywfred on 2020/4/15.
//
//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
//两个相邻元素间的距离为 1 。
//示例 1:
//输入:
//0 0 0
//0 1 0
//0 0 0
//输出:
//0 0 0
//0 1 0
//0 0 0
//示例 2:
//输入:
//0 0 0
//0 1 0
//1 1 1
//输出:
//0 0 0
//0 1 0
//1 2 1
//注意:
//给定矩阵的元素个数不超过 10000。
//给定矩阵中至少有一个元素是 0。
//矩阵中的元素只在四个方向上相邻: 上、下、左、右。
#ifndef LEETCODEINCPP_MATRIX_H
#define LEETCODEINCPP_MATRIX_H

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int y = matrix.size();
        int x = matrix[0].size();
        vector<vector<int>> ans(y, vector<int>(x, -1)); // 结果矩阵
        queue<pair<int, int>> Q; // 辅助队列
        // 坐标移动
        int dx[4]{0, 1, 0, -1};
        int dy[4]{-1, 0, 1, 0};
        // 首先标记所有为 0 的区域
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                    Q.push(make_pair(i, j));
                }
            }
        }
        // 以每个 0 作为源进行 BFS
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            int curX = cur.second;
            int curY = cur.first;
            // 如果当前为 0，则设置为 0
            for (int i = 0; i < 4; ++i) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                // 合法性判断
                if (nextX < 0 || nextX >= x || nextY < 0 || nextY >= y ||
                    ans[nextY][nextX] != -1)
                    continue;
                ans[nextY][nextX] = ans[curY][curX] + 1;
                Q.push(make_pair(nextY, nextX));
            }
        }
        return ans;
    }
};

#endif //LEETCODEINCPP_MATRIX_H
