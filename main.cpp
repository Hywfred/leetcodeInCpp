#include "daily/GameOfLife.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> input = {{0, 1, 0},
                                 {0, 0, 1},
                                 {1, 1, 1},
                                 {0, 0, 0}};
    for (const auto& row : input) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
    Solution s;
    s.gameOfLife(input);
    for (const auto& row : input) {
        for (const auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}