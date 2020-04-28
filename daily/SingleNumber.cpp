/**
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是 O (n)，空间复杂度是 O (1)。
示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
限制：
2 <= nums <= 10000
*/
#include "daily.h"

using namespace std;

vector<int> Solution::singleNumbers(vector<int>& nums) {
    vector<int> ans; // 存储结果
    int xorRes = 0; // 存储所有数字的异或结果
    int a = 0, b = 0;
    // 计算所有数字异或的结果
    for (const auto &elem: nums) {
        xorRes ^= elem;
    }
    // 找到第一位不同的位
    // 两种思路：
    // 1. 因为异或后的结果中，为 1 的位说明两个数对应位的数字不同，所以检查结果的每一个位，直至找到第一个不为 0 的位即可。
    // 2. 一个数的原码和原码的负数相与，结果中记录的就是第一个为 1 的位。故以下两种方式均可。
    auto bitOne = xorRes & (-xorRes);
    // auto bitOne = 0x01;
    // while (!(xorRes & bitOne)) {
    //     bitOne <<= 1;
    // }
    // 此时在 bitOne 这一位这两个出现一次的数字的位是不同的
    // 根据该位进行分组即可将两个值分开
    for (const auto &elem: nums) {
        if (elem & bitOne) {
            a ^= elem;
        } else {
            b ^= elem;
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}