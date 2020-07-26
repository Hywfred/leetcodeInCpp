/**
 * https://leetcode-cn.com/problems/split-array-largest-sum/
给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
注意:
数组长度 n 满足以下条件:
1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:
输入:
nums = [7,2,5,10,8]
m = 2
输出:
18
解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 */
#include "daily.h"

using namespace std;

int split(vector<int> &nums, int begin, int m, vector<vector<int>> &memo) {
    if (memo[begin][m] != -1) return memo[begin][m];
    int end = nums.size();
    int len = end - begin;
    if (m == 1) {
        int tmp = 0;
        for (int i = begin; i < end; ++i) tmp += nums[i];
        return tmp;
    }
    int min_max = INT_MAX;
    int sum = 0;
    int cur_max = -1;
    for (int i = begin + 1; i <= end - m + 1; ++i) {
        sum += nums[i - 1];
        int tmp = split(nums, i, m - 1, memo);
        cur_max = sum > tmp ? sum : tmp;
        min_max = min_max < cur_max ? min_max : cur_max;
    }
    // 会有重复，所以使用 memo 记录有的数据
    // cout << "begin: " << begin << "\tm: " << m << "\tresult: " << min_max << endl;
    memo[begin][m] = min_max;
    return min_max;
}

int Solution::splitArray(vector<int> &nums, int m) {
    int len = nums.size();
    if (m >= len) {
        int min_max = -1;
        for (auto num : nums) {
            if (num > min_max) min_max = num;
        }
        return min_max;
    }
    vector<vector<int>> memo(len, vector<int>(m + 1, -1));
    return split(nums, 0, m, memo);
}