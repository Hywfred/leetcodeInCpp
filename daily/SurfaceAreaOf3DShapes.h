//
// Created by Hywfred on 2020/3/25.
//
//在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
//每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
//请你返回最终形体的表面积。
//示例 1：
//输入：[[2]]
//输出：10
//示例 2：
//输入：[[1,2],[3,4]]
//输出：34
//示例 3：
//输入：[[1,0],[0,2]]
//输出：16
//示例 4：
//输入：[[1,1,1],[1,0,1],[1,1,1]]
//输出：32
//示例 5：
//输入：[[2,2,2],[2,1,2],[2,2,2]]
//输出：46
//提示：
//1 <= N <= 50
//0 <= grid[i][j] <= 50
#ifndef LEETCODEINCPP_SURFACEAREAOF3DSHAPES_H
#define LEETCODEINCPP_SURFACEAREAOF3DSHAPES_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 利用投影
    int surfaceArea(vector<vector<int>> &grid) {
        int len = grid.size();
        if (!len) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                int cellVal = grid[i][j];
                if (!cellVal) {
                    continue;
                }
                int area = 6 * cellVal - 2 * (cellVal - 1);
                // 左侧
                int left = i > 0 ? grid[i-1][j] : 0;
                int minV = min(cellVal, left);
                area -= minV;
                // 右侧
                int right = i < len - 1 ? grid[i + 1][j] : 0;
                minV = min(cellVal, right);
                area -= minV;
                // 上方
                int top = j > 0 ? grid[i][j - 1] : 0;
                minV = min(cellVal, top);
                area -= minV;
                // 下方
                int bottom = j < len - 1 ? grid[i][j + 1] : 0;
                minV = min(cellVal, bottom);
                area -= minV;
                ans += area;
            }
        }
        return ans;
    }
    /*
     * // 左右表面积
        int n = len;
        while (n) {
            int maxH = 0;
            for (int elem : grid[n - 1]) {
                if (elem > maxH) {
                    maxH = elem;
                }
            }
            ans += maxH << 1;
            --n;
        }
        // 前后表面积
        n = len;
        while (n) {
            int maxH = 0;
            for (int i = 0; i < len; ++i) {
                if (grid[i][n - 1] > maxH) {
                    maxH = grid[i][n - 1];
                }
            }
            ans += maxH << 1;
            --n;
        }
        // 上下表面积
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (grid[i][j]) {
                    ans += 2;
                }
            }
        }
     */
};

#endif //LEETCODEINCPP_SURFACEAREAOF3DSHAPES_H
