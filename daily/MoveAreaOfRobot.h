//
// Created by Hywfred on 2020/4/8.
//
//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//示例 1：
//输入：m = 2, n = 3, k = 1
//输出：3
//示例 1：
//输入：m = 3, n = 1, k = 0
//输出：1
//提示：
//1 <= n,m <= 100
//0 <= k <= 20
#ifndef LEETCODEINCPP_MOVEAREAOFROBOT_H
#define LEETCODEINCPP_MOVEAREAOFROBOT_H
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int dx[4]{1, 0};
        int dy[4]{0, 1};
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> reachable;
        reachable.push(make_pair(0, 0));
        int ans = 1;
        visited[0][0] = true;
        while (!reachable.empty()) {
            // 出队列，然后将可到达的点入队列
            auto curr = reachable.front();
            reachable.pop();
            for (int i = 0; i < 2; ++i) {
                int nextX = curr.second + dx[i];
                int nextY = curr.first + dy[i];
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || visited[nextY][nextX]) {
                    continue;
                }
                int m1 = 0, m2 = 0;
                int n1 = 0, n2 = 0;
                visited[nextY][nextX] = true;
                if (nextY >= 10) {
                    m1 = nextY / 10;
                    m2 = nextY % 10;
                } else {
                    m2 = nextY;
                }
                if (nextX >= 10) {
                    n1 = nextX / 10;
                    n2 = nextX % 10;
                } else {
                    n2 = nextX;
                }
                if (m1 + m2 + n1 + n2 <= k) {
                    reachable.push(make_pair(nextY, nextX));
                    ++ans;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODEINCPP_MOVEAREAOFROBOT_H
