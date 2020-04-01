#include "daily/MaxNestingDepthOfValidParenthesesStrings.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    auto ans = s.maxDepthAfterSplit("(()())");
    for (auto elem : ans) {
        cout << elem << " ";
    }
    cout << endl;
    ans = s.maxDepthAfterSplit("()(())()");
    for (auto elem : ans) {
        cout << elem << " ";
    }
    cout << endl;
    ans = s.maxDepthAfterSplit("()((()))()");
    for (auto elem : ans) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}