#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, merge2_sorted_lists) {
    Solution s;

    vector<int> v1{1, 2, 4};
    vector<int> v2{1, 3, 4};
    auto l1 = NewList(v1);
    auto l2 = NewList(v2);
    auto ans = s.mergeTwoLists(l1, l2);
    Print(ans);
    vector<int> res{1,1, 2, 3, 4, 4};
    int index = 0;
    while (ans) {
        EXPECT_EQ(ans->val, res[index++]);
        ans = ans->next;
    }


    v1 = {};
    v2 = {1, 3, 4};
    l1 = NewList(v1);
    l2 = NewList(v2);
    ans = s.mergeTwoLists(l1, l2);
    Print(ans);
    res = {1, 3, 4};
    index = 0;
    while (ans) {
        EXPECT_EQ(ans->val, res[index++]);
        ans = ans->next;
    }


    v1 = {4, 9, 75};
    v2 = {1, 3, 4, 18, 44};
    l1 = NewList(v1);
    l2 = NewList(v2);
    ans = s.mergeTwoLists(l1, l2);
    Print(ans);
    res = {1, 3, 4, 4, 9, 18, 44, 75};
    index = 0;
    while (ans) {
        EXPECT_EQ(ans->val, res[index++]);
        ans = ans->next;
    }
}