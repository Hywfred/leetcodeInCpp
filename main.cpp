#include <iostream>
#include <string>
#include "daily/GreatestCommonDivisor.h"
#include "test.h"

using namespace std;

int main() {
    int a = 0;
//    process(a);
//    process(1);
//    process(std::move(a));
    forward(1);
//    forward(a);
    forward(move(a));
    return 0;
}