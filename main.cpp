#include <iostream>
#include <string>
#include <algorithm>
#include "test.h"
#include "daily/CompressString.h"
using namespace std;


int main() {
    cout << dec << int('A') <<  " " << int('a');
    Solution s;
    cout << s.compressString("aabbccddd");
    return 0;
}