#include "Sort.h"
#include "daily/SortAnArray.h"
using namespace std;

int main() {
    auto input = SortTestHelper::generateRandomArray(10, -50, 50);
    for (int elem : input) {
        cout << elem << " ";
    }
    cout << endl;
    Solution s;
    input = {1};
    s.sortArray(input);
    for (int elem : input) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}