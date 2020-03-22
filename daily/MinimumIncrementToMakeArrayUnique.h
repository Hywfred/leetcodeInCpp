//
// Created by Hywfred on 2020/3/22.
//
//给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
//返回使 A 中的每个值都是唯一的最少操作次数。
//示例 1:
//输入：[1,2,2]
//输出：1
//解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
//示例 2:
//输入：[3,2,1,2,1,7]
//输出：6
//解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
//可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
//提示：
//0 <= A.length <= 40000
//0 <= A[i] < 40000
#ifndef LEETCODEINCPP_MINIMUMINCREMENTTOMAKEARRAYUNIQUE_H
#define LEETCODEINCPP_MINIMUMINCREMENTTOMAKEARRAYUNIQUE_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &A) {
        int len = A.size();
        int ans = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < len; ++i) {
            int pre = A[i - 1];
            if (A[i] <= pre) {
                int tmp = A[i];
                A[i] = pre + 1;
                ans += pre + 1 - tmp;
            }
        }
        return ans;
    }

    int minIncrementForUniqueTimeout3(vector<int> &A) {
        int len = A.size();
        int ans = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < len; ++i) {
            while (A[i] <= A[i - 1]) {
                A[i]++;
                ans++;
            }
        }
        return ans;
    }

    int minIncrementForUniqueTimeout2(vector<int> &A) {
        int len = A.size();
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            while (find(A.begin(), A.begin() + i, A[i]) < A.begin() + i) {
                A[i]++;
                ans++;
            }
        }
        return ans;
    }

    int minIncrementForUniqueTimeout(vector<int> &A) {
        int len = A.size();
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            while (count(A.begin(), A.begin() + i, A[i])) {
                A[i]++;
                ans++;
            }
        }
        return ans;
    }
};

#endif //LEETCODEINCPP_MINIMUMINCREMENTTOMAKEARRAYUNIQUE_H
