#include <algorithm>
#include <unordered_set>

#include "daily.h"

using namespace std;

/**
 * 将小数组哈希
 */
vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    // 保证 nums1 的数量少
    if (len1 > len2) nums1.swap(nums2);
    unordered_multiset<int> numset;
    for (int i = 0; i < nums1.size(); ++i) { numset.insert(nums1[i]); }
    vector<int> ans;
    for (int i = 0; i < nums2.size(); ++i) {
        auto it = numset.find(nums2[i]);
        if (it != numset.end()) {
            ans.push_back(nums2[i]);
            numset.erase(it);
        }
    }
    return ans;
}
/**
 * 将大数组哈希
 */
// vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) {
//     int len1 = nums1.size();
//     int len2 = nums2.size();
//     // 保证 nums1 的数量少
//     if (len1 > len2) nums1.swap(nums2);
//     unordered_multiset<int> numset;
//     for (int i = 0; i < nums2.size(); ++i) { numset.insert(nums2[i]); }
//     vector<int> ans;
//     for (int i = 0; i < nums1.size(); ++i) {
//         auto it = numset.find(nums1[i]);
//         if (it != numset.end()) {
//             ans.push_back(nums1[i]);
//             numset.erase(it);
//         }
//     }
//     return ans;
// }

/**
 * 下面的方法时间复杂度为 O(NlogN)-->排序
 */
// vector<int> helper(vector<int> &v1, vector<int> &v2) {
//     if (v1.empty() || v2.empty()) return {};
//     sort(v1.begin(), v1.end());
//     sort(v2.begin(), v2.end());
//     int len1 = v1.size();
//     int len2 = v2.size();
//     if (v1[0] > v2[len2 - 1] || v1[len1 - 1] < v2[0]) return {};
//     vector<int> ans;
//     int i = 0, j = 0;
//     while (i < len1 && j < len2) {
//         if (v1[i] < v2[j])
//             ++i;
//         else if (v2[j] < v1[i])
//             ++j;
//         else {
//             ans.push_back(v1[i]);
//             ++i, ++j;
//         }
//     }
//     return ans;
// }

// vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2) { return helper(nums1, nums2); }