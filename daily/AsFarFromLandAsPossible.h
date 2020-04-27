//
// Created by Hywfred on 2020/3/29.
//
//你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
//我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
//如果我们的地图上只有陆地或者海洋，请返回 -1。
//示例 1：
//输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释：
//海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
//示例 2：
//输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释：
//海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
//提示：
//1 <= grid.length == grid[0].length <= 100
//grid[i][j] 不是 0 就是 1
#ifndef LEETCODEINCPP_ASFARFROMLANDASPOSSIBLE_H
#define LEETCODEINCPP_ASFARFROMLANDASPOSSIBLE_H

#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int dx[4] {0, 0, 1, -1};
        int dy[4] {1, -1, 0, 0};
        // 先用队列记录所有陆地
        queue<pair<int, int>> lands;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 1) {
                    lands.push(make_pair(i, j));
                }
            }
        }
        // 然后通过陆地逐渐扩散，寻找海洋，最后扩散到的海洋就是最远的海洋
        bool hasOcean = false;
        pair<int, int> curLand;
        while (!lands.empty()) {
            curLand = lands.front();
            lands.pop();
            int curX = curLand.first;
            int curY = curLand.second;
            for (int i = 0; i < 4; ++i) {
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];
                // 判断合法性
                if (nextX < 0 || nextX >= width || nextY < 0 || nextY >= height || grid[nextX][nextY] != 0) {
                    continue;
                }
                hasOcean = true;
                grid[nextX][nextY] = grid[curX][curY] + 1;
                lands.push(make_pair(nextX, nextY));
            }
        }
        if (!hasOcean) {
            return -1;
        }
        return grid[curLand.first][curLand.second] - 1;
    }
};
#endif //LEETCODEINCPP_ASFARFROMLANDASPOSSIBLE_H
