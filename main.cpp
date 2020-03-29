#include <iostream>
#include <vector>
#include "daily/ShortEncodingOfWords.h"
#include "test.h"
using namespace std;

int main() {
    Solution s;
    vector<string> input{"time", "me", "bell"};
//    input = {"me", "time"};
    cout << s.minimumLengthEncoding(input) << endl;
    return 0;
}