#include "daily/ContainerWithMostWater.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> input {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(input) << endl;
    return 0;
}