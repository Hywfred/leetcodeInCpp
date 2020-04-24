/*
 * @Author: your name
 * @Date: 2020-04-24 10:04:24
 * @LastEditTime: 2020-04-24 13:38:39
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcodeInCpp\mytest\ReversePairs-test.cpp
 */
#include "daily.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(mytest, ReversePair) {
    Solution s;
    vector<int> nums{7, 5, 6, 4};
    auto ans = s.reversePairs(nums);
    EXPECT_EQ(ans, 5);
    
    nums = {};
    ans = s.reversePairs(nums);
    EXPECT_EQ(ans, 0);

}