//
// Created by Hywfred on 2020/4/21.
//

#include "daily/NumOfNiceSubArrs.h"
#include <iostream>

using namespace std;

int main() {
    vector<int> input{1, 1, 2, 1, 1};
    Solution s;
    cout << s.numberOfSubarrays(input, 3) << endl;
    input = {2, 4, 6};
    cout << s.numberOfSubarrays(input, 1) << endl;
    input = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << s.numberOfSubarrays(input, 2) << endl;
    input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.numberOfSubarrays(input, 3) << endl;
    return 0;
}