//
// Created by Hywfred on 2020/4/2.
//
//根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
//给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
//示例：
//输入：
//[
//  [0,1,0],
//  [0,0,1],
//  [1,1,1],
//  [0,0,0]
//]
//输出：
//[
//  [0,0,0],
//  [1,0,1],
//  [0,1,1],
//  [0,1,0]
//]
//进阶：
//你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
#ifndef LEETCODEINCPP_GAMEOFLIFE_H
#define LEETCODEINCPP_GAMEOFLIFE_H

#include <vector>
using namespace std;
class Solution {
public:
    /*
     * 思路：
     * 使用原地算法解决。
     * 0-->0 的情况设置为 0，0-->1 的情况设置为 2
     * 1-->0 的情况设置为 3，1-->1 的情况设置为 1
     * 为此，设置辅助函数 resolve 来解析变化之前的数字
     */

    static int resolve(const int &num) {
        return num % 2;
    }

    static void gameOfLife(vector <vector<int>> &board) {
        int height = board.size();
        // 特殊情况
        if (!height) return;
        int width = board[0].size();
        if (!width) return;
        // 辅助数据
        int dx[8]{0, 0, -1, -1, -1, 1, 1, 1};
        int dy[8]{1, -1, 1, 0, -1, 1, 0, -1};
        // 判断更新后状态
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int live = 0;
                for (int k = 0; k < 8; ++k) {
                    int curX = j + dx[k];
                    int curY = i + dy[k];
                    if (curX < 0 || curX >= width || curY < 0 || curY >= height) continue;
                    if (resolve(board[curY][curX])) ++live;
                }
                // 判断状态
                if (board[i][j]) {
                    if (live < 2) {
                        board[i][j] = 3;
                    } else if (live > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (live == 3) board[i][j] = 2;
                }
            }
        }
        // 恢复状态
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};

#endif //LEETCODEINCPP_GAMEOFLIFE_H
