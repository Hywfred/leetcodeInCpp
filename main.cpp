#include "daily/RotateMatrix.h"
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 10;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << endl << b << endl;
    return 0;
}