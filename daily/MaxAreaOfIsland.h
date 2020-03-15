//
// Created by Hywfred on 2020/3/15.
//
//给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
//找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
//示例 1:
//[[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
//示例 2:
//[[0,0,0,0,0,0,0,0]]
//对于上面这个给定的矩阵, 返回 0。
//注意: 给定的矩阵grid 的长度和宽度都不超过 50。
#ifndef LEETCODEINCPP_MAXAREAOFISLAND_H
#define LEETCODEINCPP_MAXAREAOFISLAND_H

#include <vector>
using  namespace std;
class Solution {
public:
    void find(vector<vector<int>>& grid, vector<vector<bool>>& flag, int i, int j, int& area) {
        int rows = grid.size();
        int columns = grid[0].size();
        area += 1;
        flag[i][j] = true;
        if (i-1 >=0 && !flag[i-1][j] && grid[i-1][j] == 1) {
            find(grid, flag, i-1, j, area);
        }
        if (j+1 <= columns - 1 && !flag[i][j+1] && grid[i][j+1] == 1) {
            find(grid, flag, i, j+1, area);
        }
        if (i+1 <= rows-1 && !flag[i+1][j] && grid[i+1][j] == 1) {
            find(grid, flag, i+1, j, area);
        }
        if (j-1 >= 0 && !flag[i][j-1] && grid[i][j-1] == 1) {
            find(grid, flag, i, j-1, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> flag(rows, vector<bool>(columns));
        int area = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int tmp = 0;
                if (!flag[i][j] && grid[i][j] == 1) {
                    find(grid, flag, i, j, tmp);
                    area = tmp > area ? tmp : area;
                }
            }
        }

        return area;
    }
};
#endif //LEETCODEINCPP_MAXAREAOFISLAND_H
