#include "Sort.h"
#include <iostream>
using namespace std;
int main () {
    Sort s;
    vector<int> input{3, 9, 9, 34, 45, 98, 7, 2, 0};
    s.Select(input);
    for (int i = 0; i < input.size(); ++i) {
        cout << input[i] << " ";
    }
}