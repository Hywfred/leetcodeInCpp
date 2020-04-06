#include "daily/EditDistance.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    cout << s.minDistance("intention", "execution") << endl;
    cout << s.minDistance("", "execution") << endl;
    cout << s.minDistance("", "") << endl;
    return 0;
}