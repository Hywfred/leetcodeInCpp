#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, reverseK) {
    vector<int> data{1, 2, 3, 4, 5};
    auto l = NewList(data);
    Solution s;
    auto ans = s.reverseKGroup(l, 3);
    Print(ans);

    data = {1, 2, 3, 4, 5};
    l = NewList(data);
    ans = s.reverseKGroup(l, 4);
    Print(ans);

    data = {};
    l = NewList(data);
    ans = s.reverseKGroup(l, 4);
    Print(ans);

    data = {1};
    l = NewList(data);
    ans = s.reverseKGroup(l, 4);
    Print(ans);

    data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l = NewList(data);
    ans = s.reverseKGroup(l, 4);
    Print(ans);
}