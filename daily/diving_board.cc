/**
 * https://leetcode-cn.com/problems/diving-board-lcci/
 */
#include "daily.h"

using namespace std;

vector<int> Solution::divingBoard(int shorter, int longer, int k) {
    vector<int> ans;
    if (!k) return ans;
    if (shorter == longer) return vector<int>({k * shorter});
    for (int i = k; i >= 0; --i) ans.push_back(i * shorter + (k - i) * longer);
    return ans;
}