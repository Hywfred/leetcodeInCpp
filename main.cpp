#include <iostream>
#include "test1.h"
#include "Sort.h"


using namespace std;

int main() {
    auto data = SortTestHelper::generateRandomArray(20, -50, 50);
    for (int elem : data) {
        cout << elem << ", ";
    }
    cout << endl;
    Quick(data);
    for (int elem : data) {
        cout << elem << ", ";
    }
    return 0;
}