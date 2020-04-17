#include "daily/MergeIntervals.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<vector<int>> input{{1,  3},
                              {2,  6},
                              {8,  10},
                              {15, 18}};
//    input = {{1, 4},
//             {4, 5},};

    input = {{1, 4},
             {2, 3},};
    Solution s;
    auto ans = s.merge(input);
    for (auto elem : ans) {
        for (auto cell : elem) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}