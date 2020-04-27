//
// Created by Hywfred on 2020/4/20.
//
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//此外，你可以假设该网格的四条边均被水包围。
//示例 1:
//输入:
//11110
//11010
//11000
//00000
//输出: 1
//示例 2:
//输入:
//11000
//11000
//00100
//00011
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
#ifndef LEETCODEINCPP_NUMBEROFILANDS_H
#define LEETCODEINCPP_NUMBEROFILANDS_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (!grid.size() || !grid[0].size())
            return 0;
        int dx[4]{1, 0, 0, -1};
        int dy[4]{0, 1, -1, 0};
        vector<pair<int, int>> iLands;
        // 将所有 ‘1’ 放入队列
        auto rowL = grid.size();
        auto colL = grid[0].size();
        for (decltype(rowL) i = 0; i < rowL; ++i) {
            for (decltype(colL) j = 0; j < colL; ++j) {
                if (grid[i][j] == '1') iLands.push_back(make_pair(i, j));
            }
        }
        // 统计所有岛屿
        int ans = 0;
        queue<pair<int, int>> q;
        for (const auto &elem : iLands) {
            if (grid[elem.first][elem.second] == '1') {
                q.push(elem);
                while (!q.empty()) {
                    auto curP = q.front();
                    q.pop();
                    int curX = curP.second;
                    int curY = curP.first;
                    grid[curY][curX] = '2';
                    // 检查水平竖直 4 个方向是否是相连岛屿
                    int nextX, nextY;
                    for (unsigned i = 0; i < 4; ++i) {
                        // 索引检查
                        nextX = curX + dx[i];
                        nextY = curY + dy[i];
                        if (nextX < 0 || nextX >= colL || nextY < 0 || nextY >= rowL || grid[nextY][nextX] != '1')
                            continue;
                        grid[nextY][nextX] = '2';
                        q.push(make_pair(nextY, nextX));
                    }
                }
                // 更新岛屿数量
                ++ans;
            }
        }
        return ans;
    }
};

#endif //LEETCODEINCPP_NUMBEROFILANDS_H
