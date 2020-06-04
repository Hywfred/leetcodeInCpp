/**
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中
output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O (n) 时间复杂度内完成此题。
进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
 */
#include <unordered_map>

#include "daily.h"

using namespace std;

vector<int> Solution::productExceptSelf(vector<int> &nums) {
    // 思路三： 参考题解，先用 ans 存储左边乘积；然后存储右边乘积。
    // 学到的是，充分利用一切已有的空间!比如这里的 ans。
    using sizet = vector<int>::size_type;
    auto len = nums.size();
    int product = 1;
    // 计算和
    vector<int> ans(len);
    for (sizet i = 0; i != len; ++i) {
        ans[i] = product;
        product *= nums[i];
    }
    product = 1;
    for (sizet i = len - 1; i >= 0 && i < len; --i) {
        ans[i] *= product;
        product *= nums[i];
    }
    return ans;
    /*
    // 思路二： 优化掉前缀和数组，用一个变量代替
    using sizet = vector<int>::size_type;
    auto len = nums.size();
    unordered_map<sizet, int> postfix_pro(len);
    int prefix_pro = 1;  // 前缀乘积
    int product = 1;
    // 后缀乘积
    for (sizet i = len - 1; i >= 0 && i < len; --i) {
        product *= nums[i];
        postfix_pro[i] = product;
    }
    // 计算和
    vector<int> ans(len);
    for (sizet i = 0; i != len - 1; ++i) {
        ans[i] = prefix_pro * postfix_pro[i + 1];
        prefix_pro *= nums[i];
    }
    ans[len - 1] = prefix_pro;
    return ans;
    */

    /*
    // 思路一：
    // 保存前缀乘积以及后缀乘积
    using sizet = vector<int>::size_type;
    auto len = nums.size();
    unordered_map<sizet, int> prefix_pro(len);
    unordered_map<sizet, int> postfix_pro(len);
    int product = 1;
    // 前缀乘积
    for (sizet i = 0; i != len; ++i) {
        product *= nums[i];
        prefix_pro[i] = product;
    }
    // 后缀乘积
    product = 1;
    for (sizet i = len - 1; i >= 0 && i < len; --i) {
        product *= nums[i];
        postfix_pro[i] = product;
    }
    // 计算和
    vector<int> ans(len);
    ans[0] = postfix_pro[1];
    ans[len - 1] = prefix_pro[len - 2];
    for (sizet i = 1; i != len - 1; ++i) { ans[i] = prefix_pro[i - 1] * postfix_pro[i + 1]; }
    return ans;
    */
}
