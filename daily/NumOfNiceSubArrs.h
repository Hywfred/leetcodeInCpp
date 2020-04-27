/*
 给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目。
示例 1：
输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：
输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：
输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16
提示：
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        unsigned evenCounter = 0;
        unordered_map<int, unsigned> counter;
        vector<decltype(nums.size())> odds;
        int j = -1;
        for (decltype(nums.size())i = 0; i < nums.size(); ++i) {
            if (!(nums[i] % 2)) {
                ++evenCounter;
            } else {
                odds.push_back(++j);
                counter[j] = evenCounter;
                evenCounter = 0;
            }
        }
        if (odds.size() < k) return 0; // 如果奇数个数不足 k，返回 0
        // 如果最后一个数是奇数，则evenCounter设为0，否则记录实际偶数个数
        if (nums[nums.size()-1] % 2 == 0) {
            odds.push_back(++j);
            counter[j] = evenCounter;
        }
        else {
            odds.push_back(++j);
            counter[j] = 0;
        }
        for (unsigned i = 0; i < odds.size() - k; ++i) {
            ans += (counter[odds[i]] + 1) * (counter[odds[i + k]] + 1);
        }
        return ans;
    }
};