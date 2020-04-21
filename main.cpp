#include <vector>
#include <iostream>
#include "util/ListNode.h"
#include "hard/ReverseNodesInKGroup.h"

using namespace std;

int main() {
    auto input = NewList(vector<int>{1, 2, 3, 4, 5});
    Solution s;
    auto ans = s.reverseKGroup(input, 2);
    Print(ans);
    return 0;
}