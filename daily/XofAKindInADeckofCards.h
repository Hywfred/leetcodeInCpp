//
// Created by Hywfred on 2020/3/27.
//
//给定一副牌，每张牌上都写着一个整数。
//此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
//每组都有 X 张牌。
//组内所有的牌上都写着相同的整数。
//仅当你可选的 X >= 2 时返回 true。
//示例 1：
//输入：[1,2,3,4,4,3,2,1]
//输出：true
//解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
//示例 2：
//输入：[1,1,1,2,2,2,3,3]
//输出：false
//解释：没有满足要求的分组。
//示例 3：
//输入：[1]
//输出：false
//解释：没有满足要求的分组。
//示例 4：
//输入：[1,1]
//输出：true
//解释：可行的分组是 [1,1]
//示例 5：
//输入：[1,1,2,2,2,2]
//输出：true
//解释：可行的分组是 [1,1]，[2,2]，[2,2]
//提示：
//1 <= deck.length <= 10000
//0 <= deck[i] < 10000
#ifndef LEETCODEINCPP_XOFAKINDINADECKOFCARDS_H
#define LEETCODEINCPP_XOFAKINDINADECKOFCARDS_H

#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if (len < 2) {
            return false;
        }
        // 整理元素
        unordered_map<int, int> counter;
        for (int elem : deck) {
            if (counter.find(elem) != counter.end()) {
                counter[elem]++;
            } else {
                counter[elem] = 1;
            }
        }
        // 找出最小个数
        int min = 10000;
        for (auto item : counter) {
            if (item.second < min) {
                min = item.second;
            }
        }
        if (min == 1) {
            return false;
        }
        // 找出最小值的最小因子
        /*
         * 这里可以优化，没必要每个数字都遍历，只遍历素数即可。
         */
        for (int i = 2; i <= min; ++i) {
            int flag = true;
            for (auto item : counter) {
                if (item.second % i != 0) {
                    flag = false;
                }
            }
            if (flag) {
                return flag;
            }
        }
        return false;
    }
};
#endif //LEETCODEINCPP_XOFAKINDINADECKOFCARDS_H
