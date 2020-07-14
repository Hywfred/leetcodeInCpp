/**
 * https://leetcode-cn.com/problems/triangle/
 *
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */
#include <algorithm>

#include "daily.h"

using namespace std;
/**
 * 实现空间复杂度为 O(n)
 */
int Solution::minimumTotal(vector<vector<int>> &triangle) {
    int row = triangle.size();
    if (!row) return row;
    for (int i = row - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}
/**
 * 下面的算法空间复杂度不满足 O(n)，n 为行数的要求。
 */
// int helper(vector<vector<int>> &triangle, int root, int level, vector<vector<int>> &memo) {
//     if (level >= triangle.size()) return 0;
//     // 如果已经计算过则直接返回
//     if (memo[level].size() > root) return memo[level][root];
//     // 左侧最小值
//     int min_left = helper(triangle, root, level + 1, memo);
//     // 右侧最小值
//     int min_right = helper(triangle, root + 1, level + 1, memo);
//     int min = min_left < min_right ? min_left : min_right;
//     // 通过下面的打印语句可以看出 很多分支进行了重复计算
//     // cout << "level: " << level << " root: " << root << endl;
//     int sum = min + triangle[level][root];
//     if (memo[level].size() < root + 1) memo[level].push_back(sum);
//     return sum;
// }

// int Solution::minimumTotal(vector<vector<int>> &triangle) {
//     int ans = INT_MAX;
//     if (!triangle.size()) return 0;
//     vector<vector<int>> memo(triangle.size());
//     return helper(triangle, 0, 0, memo);
// }