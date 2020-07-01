/**
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
示例 1:
输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释:
长度最长的公共子数组是 [3, 2, 1]。
说明:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
 */
#include <unordered_map>
#include <unordered_set>

#include "daily.h"

using namespace std;

/**
 * 滑动窗口：判断窗口内的最大值
 */
int maxlen(vector<int> &A, int indexa, vector<int> &B, int indexb, int len) {
    int ret = 0;
    int countnum = 0;
    for (int i = 0; i < len; i++) {
        if (A[indexa + i] == B[indexb + i]) {
            countnum++;
        } else if (countnum > 0) {
            ret = max(ret, countnum);
            countnum = 0;
        }
    }
    return max(ret, countnum);
}

int helper(vector<int> &A, vector<int> &B) {
    int na = A.size();
    int nb = B.size();
    int ret = 0;
    //进入时候的处理
    for (int len = 1; len <= na; len++) {
        int tmplen = maxlen(A, 0, B, nb - len, len);
        ret = max(ret, tmplen);
    }
    //中间过程的处理
    for (int indexb = nb; indexb - na >= 0; indexb--) {
        int tmplen = maxlen(A, 0, B, indexb - na, na);
        ret = max(ret, tmplen);
    }
    //出去时的处理
    for (int len = na; len > 0; len--) {
        int tmplen = maxlen(A, na - len, B, 0, len);
        ret = max(ret, tmplen);
    }
    return ret;
}

int Solution::findLength(vector<int> &A, vector<int> &B) { return A.size() <= B.size() ? helper(A, B) : helper(B, A); }

/**
 * 该方法超时，因为有很多次的重复判断
 * 比如题目中的例子 3 2 1 分别都进行了判断。
 * 时间复杂度 O(N^2)
 */
// int Solution::findLength(vector<int> &A, vector<int> &B) {
//     int len_a = A.size();
//     int len_b = B.size();
//     int ans = 0;  // 存储最终结果
//     // 将 B 哈希化
//     unordered_map<int, unordered_set<int>> dict_b;
//     for (int i = 0; i != len_b; ++i) { dict_b[B[i]].insert(i); }
//     // 遍历 A
//     for (int i = 0; i != len_a;) {
//         // 首先，对于 A 中的当前元素，如果 B 中没有
//         // 那么直接跳过循环
//         // 这种情况下没有以此元素开头的公共子数组
//         if (!dict_b.count(A[i])) {
//             ++i;
//             continue;
//         }
//         // 对于 B 中每一个与 A 中当前元素值相同的元素
//         // 进行长度判断和更新
//         for (auto j : dict_b[A[i]]) {
//             int len = 0;
//             int tmp_i = i;
//             while (tmp_i < len_a && j < len_b && A[tmp_i] == B[j]) {
//                 ++len;
//                 if (len > ans) ans = len;
//                 ++tmp_i, ++j;
//             }
//             if (tmp_i >= len_a) return ans;
//         }
//         ++i;
//     }
//     return ans;
// }