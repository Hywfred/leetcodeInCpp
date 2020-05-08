/**
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4
 */
#include <queue>

#include "daily.h"

using namespace std;
/**
 * 下面是错误版本 应该用动态规划去做 具体参考 leetcode 题解
 * /
/**
 * 思路：先将所有 1 存储，然后遍历每一个 1
 * 对于每一个 1，只查看其右下方的元素是否为 1，如果为 1，则更新为 2，表示遍历过。
 * 然后查看当前 1 所能连接的最大正方形。
 */
int Solution::maximalSquare(vector<vector<char>> &matrix) {
    vector<pair<int, int>> ones;   // 存储所有 1 的位置
    queue<pair<int, int>> square;  // 用于查看当前 1 所连接的最大正方形
    // 先找出所有的 1
    int row = matrix.size();
    if (!row) return 0;
    int col = matrix[0].size();
    for (decltype(row) r = 0; r < row; ++r) {
        for (decltype(col) c = 0; c < col; ++c) {
            if (matrix[r][c] == '1') ones.push_back({r, c});
        }
    }
    // 遍历所有 1 查看其能连接的最大正方形
    int sideL = 0; 
    int ans = ones.size() ? 1 : 0;
    int dx[3]{1, 0, 1};
    int dy[3]{0, 1, 1};
    for (const auto &one : ones) {
        if (matrix[one.first][one.second] != '1') continue;
        sideL = 1;
        square.push(one);
        int count = 0;
        bool over = false;
        while (!square.empty()) {
            auto pos = square.front();
            square.pop();
            auto curR = pos.first;
            auto curC = pos.second;
            for (int i = 0; i < 3; ++i) {
                auto newR = curR + dy[i];
                auto newC = curC + dx[i];
                if (newR >= row || newC >= col || matrix[newR][newC] == '0') {
                    over = true;
                    break;
                }
                if (matrix[newR][newC] == '1') {
                    matrix[newR][newC] = '2';
                    square.push({newR, newC});
                    ++count;
                }
            }
            if (over) {
                queue<pair<int, int>>().swap(square);  // 清空 square
                break;
            }
            if (count == sideL * 2 + 1) {
                ++sideL;
                ans = sideL;
                count = 0;
            }
        }
    }
    return ans * ans;
}