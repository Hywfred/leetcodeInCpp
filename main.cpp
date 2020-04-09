#include "daily/GenerateParentheses.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    auto ans = s.generateParenthesis(4);
    for (string elem : ans) {
        cout << elem << endl;
    }
    return 0;
}