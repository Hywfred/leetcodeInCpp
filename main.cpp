#include <iostream>
#include <vector>
#include "daily/TheLastNumber.h"
#include "test.h"
using namespace std;

int main() {
    Solution s;
    cout << s.lastRemaining(5, 3) << endl;
    cout << s.lastRemaining(10, 17) << endl;
    cout << s.lastRemaining(70866, 116922) << endl;
    return 0;
}