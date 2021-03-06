//
// Created by Hywfred on 2020/4/11.
//
//你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
//每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
//你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
//每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
//你的目标是确切地知道 F 的值是多少。
//无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
//示例 1：
//输入：K = 1, N = 2
//输出：2
//解释：
//鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
//否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
//如果它没碎，那么我们肯定知道 F = 2 。
//因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
//示例 2：
//输入：K = 2, N = 6
//输出：3
//示例 3：
//输入：K = 3, N = 14
//输出：4
//提示：
//1 <= K <= 100
//1 <= N <= 10000
#ifndef LEETCODEINCPP_SUPEREGGDROP_H
#define LEETCODEINCPP_SUPEREGGDROP_H

#include <vector>
using namespace std;
class Solution {
public:
    static int superEggDrop(int K, int N) {
        // dp[i][j] 代表 i 个鸡蛋掉 j 次，最多可以测到哪一层楼（F）。
        vector<vector<int>> dp(K + 1, vector<int>(N+1));
        // 初始值：
        // 如果 i=0，那么肯定测不到楼层，dp[0][j] = 0
        // 如果 j=1，也就是只允许掉一次，那么最多可以测出一层楼 dp[i][1]=1
        // 如果是 dp[1][j]，1 个鸡蛋掉 j 次，那么最多可以测出 j 层楼，前 j-1 次都没碎
        // j 的最大值为 N，因为最多只需要掉 N 次就可以测万所有的 N 层楼。
        // dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + 1
        for (int j = 1; j <= N; ++j) {
            for (int i = 1; i <= K; ++i) {
                // 当 j=1 时，这一条语句可以保证 dp[i][1]=1
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
                if (dp[i][j] >= N) return j;
            }
        }
        return N;
    }
};

#endif //LEETCODEINCPP_SUPEREGGDROP_H
