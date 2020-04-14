#include "daily/AddTwoNumbers.h"
#include <vector>

using namespace std;

int main() {
    vector<int> input{9,9,9};
    auto l1 = NewList(input);
    input = {1, 2, 3};
    auto l2 = NewList(input);
    Solution s;
    auto l3 = s.addTwoNumbers(l1, l2);
    Print(l3);
    return 0;
}