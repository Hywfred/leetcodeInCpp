#include "daily.h"

using namespace std;

vector<vector<int>> ans;
vector<bool> used;

/**
 * 回溯算法核心
 * 在当前路径和初始数组长度相同时退出
 */
void backTrace(const vector<int> &nums, vector<int> &path) {
    // 退出条件
    if (path.size() == nums.size()) {
        ans.push_back(vector<int>(path));
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            path.push_back(nums[i]);
            used[i] = true;
            backTrace(nums, path);
            // 回复状态
            path.erase(path.end() - 1);
            used[i] = false;
        }
    }
}

/**
 * 回溯法解决全排列问题
 */
std::vector<std::vector<int>> Solution::permute(std::vector<int>& nums) {
    used.assign(nums.size(), false);
    vector<int> path;
    backTrace(nums, path);
    return ans;
}