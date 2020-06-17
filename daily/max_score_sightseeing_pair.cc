/**
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
返回一对观光景点能取得的最高分。
示例：
输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
提示：
2 <= A.length <= 50000
1 <= A[i] <= 1000
 */
#include "daily.h"

using namespace std;

/**
 * 分析：
 * 如果 A[i] + A[j] + i - j > A[i1] + A[j] + i1 - j
 * 得出 A[i] + i > A[i1] + i1
 * 也就是说如果上式成立，那么不管 j 代表的是哪一个元素，
 * 前者的观光分一定大于后者，i1 处的也就不用再计算了
 * 再看 A[i] + A[j] + i - j，分为两部分：
 * A[i] + i，也就是上面分析的和 A[j] - j
 * 如果 A[i] + A[j] + i - j 最大，那么 A[i] + i 最大且
 * A[j] - j 最大即可，同时满足 i < j
 */
int Solution::maxScoreSightseeingPair(vector<int> &A) {
    int ans = 0;
    int i = 0, sum = A[0];      // i 代表当前位置下标, sum 代表最大和
    int j = 1, sub = A[1] - 1;  // j 代表当前当前位置下标， sub 代表最大的差
    while (true) {
        ++i, ++j;
        if (j >= A.size()) break;
        // 更新 sum 时注意，先算一下当前最大值
        // 然后更新 sub 以使 j > i 成立
        if (A[i] + i > sum) {
            if (sum + sub > ans) ans = sum + sub;
            sum = A[i] + i;
            sub = A[j] - j;
        }
        if (A[j] - j > sub) sub = A[j] - j;
    }
    return sum + sub > ans ? sum + sub : ans;
}

/**
 * brute force
 * timeout
 */
// int Solution::maxScoreSightseeingPair(vector<int> &A) {
//     int ans = 0;
//     for (int i = 0; i != A.size() - 1; ++i) {
//         for (int j = i + 1; j != A.size(); ++j) {
//             int dis = A[i] + A[j] + i - j;
//             if (dis > ans) ans = dis;
//         }
//     }
//     return ans;
// }