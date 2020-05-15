/**
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 */
#include <unordered_map>

#include "daily.h"

using namespace std;

/**
 * 思路：暴力法复杂度为 O(n^3)，则考虑空间换取时间，空间的查找时间为常数级，选择哈希
 * 谁做键，谁做值。具体到本题，我们需要知道当前 j 前面和为 sum[j] - k 的和的数量，
 * 所以和做键，数量做值。
 */
int Solution::subarraySum(vector<int> &nums, int k) {
    if (nums.empty()) return 0;  // 如果数组为空，返回 0.
    int ans = 0, sum = 0;
    unordered_map<int, int> dict{{0, 1}};
    for (const auto &num : nums) {
        sum += num;
        ans += dict[sum - k];  // sum[j] - sum[i] = k, sum[i] 出现次数
        ++dict[sum];           // 记录当前和
    }
    return ans;
}