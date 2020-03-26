//
// Created by Hywfred on 2020/3/26.
//
//在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。
//车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他友方（白色）象进入同一个方格。
//返回车能够在一次移动中捕获到的卒的数量。
//示例 1：
//输入：[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//输出：3
//解释：
//在本例中，车能够捕获所有的卒。
//示例 2：
//输入：[[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//输出：0
//解释：
//象阻止了车捕获任何卒。
//示例 3：
//输入：[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
//输出：3
//解释：
//车可以捕获位置 b5，d6 和 f5 的卒。
//提示：
//board.length == board[i].length == 8
//board[i][j] 可以是 'R'，'.'，'B' 或 'p'
//只有一个格子上存在 board[i][j] == 'R'
#ifndef LEETCODEINCPP_AVAILABLECAPTURESFORROOK_H
#define LEETCODEINCPP_AVAILABLECAPTURESFORROOK_H

#include <vector>
using namespace std;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        if (board.empty()) {
            return 0;
        }
        int height = board.size();
        int width = board[0].size();
        int ans = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // 找到车
                if (board[i][j] == 'R') {
                    int y = i, x = j;
                    // 北
                    while (true) {
                        --y;
                        if (y <= 0 || board[y][x] == 'B') {
                            break;
                        }
                        if (board[y][x] == 'p') {
                            ++ans;
                            break;
                        }
                    }
                    y = i;
                    // 南
                    while (true) {
                        ++y;
                        if (y >= height || board[y][x] == 'B') {
                            break;
                        }
                        if (board[y][x] == 'p') {
                            ++ans;
                            break;
                        }
                    }
                    y = i;
                    // 西
                    while (true) {
                        --x;
                        if (x <= 0 || board[y][x] == 'B') {
                            break;
                        }
                        if (board[y][x] == 'p') {
                            ++ans;
                            break;
                        }
                    }
                    x = j;
                    // 东
                    while (true) {
                        ++x;
                        if (x >= width || board[y][x] == 'B') {
                            break;
                        }
                        if (board[y][x] == 'p') {
                            ++ans;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODEINCPP_AVAILABLECAPTURESFORROOK_H
