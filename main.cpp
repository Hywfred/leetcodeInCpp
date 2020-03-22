<<<<<<< HEAD
#include "daily/MinimumIncrementToMakeArrayUnique.h"
#include <iostream>
using namespace std;

int main() {
    Solution s;
    vector<int> input{1, 2, 2};
    input = {3,2,1,2,1,7};
    int ans = s.minIncrementForUnique(input);
    cout << ans << endl;
=======
#include "daily/WaterAndJug.h"
#include <iostream>
#include "Sort.h"

using  namespace std;

int main() {
    vector<int> input = SortTestHelper::generateRandomArray(10, 1, 100);
    for (int elem : input) {
        cout << elem << " ";
    }
    cout << endl;
    Sort s;
    s.Quick2(input);
    for (int elem : input) {
        cout << elem << " ";
    }
>>>>>>> 07a1004344996100382f92618bade856ea99ee1a
    return 0;
}