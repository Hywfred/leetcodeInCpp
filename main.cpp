#include <iostream>
#include <string>
#include "daily/GreatestCommonDivisor.h"
#include "Sort.h"

using namespace std;

int main() {
    Solution s;
    cout << s.gcdOfStrings("ABABAB", "ABAB") << endl;
    vector<int> input{5, 4, 3, 2, 1, 0, -1};
    Sort sort;
//    sort.Insert(input);
//    sort.Shell(input);
    input = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//    sort.Heap(input);
//    sort.Merge(input);
    sort.Quick(input);
    for (int elem : input) {
        cout << elem << " ";
    }
    return 0;
}