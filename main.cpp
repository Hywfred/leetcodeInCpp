#include "daily/Atoi.h"
#include <iostream>
using namespace std;

int main() {
    cout << Solution::myAtoi("42") << endl;
    cout << Solution::myAtoi("    -42") << endl;
    cout << Solution::myAtoi("4193 with words") << endl;
    cout << Solution::myAtoi("words and 987") << endl;
    cout << Solution::myAtoi("-91283472332") << endl;
    cout << Solution::myAtoi("-2147483648") << endl;
    cout << Solution::myAtoi("2147483648") << endl;
    cout << Solution::myAtoi("2147483647") << endl;
    cout << Solution::myAtoi("2147483646") << endl;
    return 0;
}