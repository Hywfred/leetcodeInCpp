#include "daily/MinimumIncrementToMakeArrayUnique.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    vector<int> input{1, 2, 2};
    input = {3,2,1,2,1,7};
    int ans = s.minIncrementForUnique(input);
    cout << ans << endl;
    return 0;
}