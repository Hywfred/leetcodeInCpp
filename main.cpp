#include "Sort.h"

using namespace std;

int main() {
    auto data = SortTestHelper::generateRandomArray(30, -50, 50);
    for (int elem : data) {
        cout << elem << ", ";
    }
    cout << endl;
    Sort s;
    s.quickSort(data, 0, data.size() - 1);
    for (int elem : data) {
        cout << elem << ", ";
    }
    return 0;
}