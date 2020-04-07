#include "daily/RotateMatrix.h"
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> matrix{{1, 2,}, {3, 4}};
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    matrix = {{1}};
    Solution s;
    s.rotate(matrix);
    for (auto row : matrix) {
        for (auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}