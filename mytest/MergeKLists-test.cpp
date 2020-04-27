#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, mergeKLists) {
    Solution s;
    vector<int> v1{1, 4, 5};
    vector<int> v2{1, 3, 4, 7};
    vector<int> v3{2, 6};
    auto l1 = NewList(v1);
    auto l2 = NewList(v2);
    auto l3 = NewList(v3);
    auto input = vector<ListNode *>({l1, l2, l3});
    auto ans = s.mergeKLists(input);
    Print(ans);
}