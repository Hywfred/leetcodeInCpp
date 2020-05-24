#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, median_of_two_sorted_arrays) {
    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    Solution s;
    auto ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;

    nums1 = {1, 11};
    nums2 = {2, 6};
    ans = s.findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;
}