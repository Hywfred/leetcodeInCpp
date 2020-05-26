/**
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
示例 1:
输入: [1,3,4,2,2]
输出: 2
示例 2:
输入: [3,1,3,4,2]
输出: 3
说明：
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/
#include "daily.h"

using namespace std;

/**
 * 思路：根据提议，时间复杂度应当为 O(NlogN)，
 * 考虑使用归并排序的思路，在排序过程中找出相等项。
 *
 * 上面的思路没有走通，首先归并排序需要额外 O(N) 的存储空间
 * 不满足条件 2
 *
 * 参考题解，可用二分查找，每次猜一个数（中位数）然后看看
 * 小于等于该数的个数是否严格大于该数，抽屉原理
 * 也可利用快慢指针。
 */
int Solution::findDuplicate(vector<int> &nums) {
    int len = nums.size();
    int left = 1, right = len - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        unsigned count = 0;
        // 统计 nums 中 <= mid 的数字个数
        for (auto &num : nums) {
            if (num <= mid) ++count;
        }
        // 如果 count > mid，根据抽屉原理，重复的数字肯定在 1-4 之间
        if (count > mid)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}