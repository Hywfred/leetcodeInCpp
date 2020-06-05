/**
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
*/
#include "daily.h"

using namespace std;

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix) {
    // 边界情况
    auto height = matrix.size();
    if (!height) return {};
    auto width = matrix[0].size();
    if (!width) return {};
    // 至少有一个元素
    int dx[4]{1, 0, -1, 0};
    int dy[4]{0, 1, 0, -1};
    int d = 0;         // 记录当前方向
    int h = 0, w = 0;  // 记录当前索引
    int cycle = 0;     // 记录当前是第几轮
    vector<int> ans;
    for (int i = 0; i != height * width; ++i) {
        // 到达右边界
        if (!d && w >= width - 1 - cycle) d = ++d % 4;
        // 到达下边界
        if (d == 1 && h >= height - 1 - cycle) d = ++d % 4;
        // 到达左边界
        if (d == 2 && w <= cycle) d = ++d % 4;
        // 到达上边界
        if (d == 3 && h <= cycle + 1) {
            d = ++d % 4;
            // 进入下一轮
            ++cycle;
        }

        ans.push_back(matrix[h][w]);
        h += dy[d];
        w += dx[d];
    }
    return ans;
}