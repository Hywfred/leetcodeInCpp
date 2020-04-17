#include "daily/JumpGame.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> input{2, 3, 1, 1, 4};
    input = {3, 2, 1, 0, 4};
    Solution s;
    cout << boolalpha << s.canJump(input);
    return 0;
}