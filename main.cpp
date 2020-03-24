#include "daily/TheMassuse.h"
#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    auto data = SortTestHelper::generateRandomArray(10, 1, 50);
    for (int elem : data) {
        cout << elem << ", ";
    }
    cout << endl;
    Solution s;
    cout << s.massage(data);
    return 0;
}