#include "daily/NumberOfIlands.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<vector<char>> input{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };
//    input = {
//            {'1', '1', '0', '0', '0'},
//            {'1', '1', '0', '0', '0'},
//            {'0', '0', '1', '0', '0'},
//            {'0', '0', '0', '1', '1'}
//    };
    Solution s;
    cout << s.numIslands(input) << endl;
    return 0;
}