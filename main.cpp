#include "daily/MoveAreaOfRobot.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    cout << s.movingCount(11, 8, 16) << endl;
    cout << s.movingCount(16, 8, 4) << endl;
    cout << s.movingCount(2, 3, 1) << endl;
    cout << s.movingCount(3, 1, 0) << endl;
    return 0;
}