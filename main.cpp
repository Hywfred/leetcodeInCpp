#include "daily/WaterAndJug.h"
#include <iostream>
#include "Sort.h"

using  namespace std;

int main() {
    vector<int> input = SortTestHelper::generateRandomArray(20, -100, 100);
    for (int elem : input) {
        cout << elem << " ";
    }
    cout << endl;
    Sort s;
    s.Quick2(input);
    for (int elem : input) {
        cout << elem << " ";
    }
    return 0;
}