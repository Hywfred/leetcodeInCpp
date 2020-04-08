//
// Created by Hywfred on 2020/4/7.
//
//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//不占用额外内存空间能否做到？
//示例 1:
//给定 matrix =
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//示例 2:
//给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//],
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]
#ifndef LEETCODEINCPP_ROTATEMATRIX_H
#define LEETCODEINCPP_ROTATEMATRIX_H

#include <vector>
using namespace std;
class Solution {
public:
    // 此外还有一种思路就是 先沿对角线旋转，然后左右翻转。
    void rotate(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (!height) return;
        int row = height % 2 ? height / 2 + 1 : height / 2;
        int col = height / 2;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[height - 1 - j][i];
                matrix[height - 1 - j][i] = matrix[height - 1 - i][height - 1 - j];
                matrix[height - 1 - i][height - 1 - j] = matrix[j][height - 1 - i];
                matrix[j][height - 1 - i] = tmp;
            }
        }
    }
};
#endif //LEETCODEINCPP_ROTATEMATRIX_H
