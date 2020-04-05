#include "daily/TrappingRainWater.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> input{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(input) << endl;
    return 0;
}