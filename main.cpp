#include "daily/Matrix.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> input {{0,0,0},{0,1,0},{1,1,1}};
    input = {{1,0,1,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    Solution s;
    auto ans = s.updateMatrix(input);
    for (auto elem : ans) {
        for (auto cell : elem) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}