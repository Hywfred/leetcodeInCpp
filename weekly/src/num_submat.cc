#include "196.h"

using namespace std;

int numSubmat(vector<vector<int>> &mat) {
    // int ht = mat.size();
    // int wd = mat[0].size();
    // // 向右或向下寻找
    // int dx[2]{1, 0};
    // int dy[2]{0, 1};
    // // 所有的 1
    // vector<pair<int, int>> ones;
    // for (int i = 0; i < ht; ++i) {
    //     for (int j = 0; j < wd; ++j) {
    //         if (mat[i][j]) ones.push_back({i, j});
    //     }
    // }
    // // 遍历
    // for (int i = 0; i < ones.size(); ++i) {
    //     int cury = ones[i].first;
    //     int curx = ones[i].second;
    //     for (int j = 1; j <= ht; ++j) {
    //         for (int k = 1; k <= wd; ++k) {
    //             if (j == 1 && k == 1) continue;
    //             if (cury + 1 < ht && mat[cury + 1][curx] == 1) }
    //     }
    // }
}