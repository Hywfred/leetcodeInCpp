#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
int total_air;
//

int main(int argv, char *args[]) {
    pair<int, int> p;
    vector<pair<int, int>> v;
    cout << p.first << " " << p.second << endl;

    return 0;
}

// void recover(unordered_map<int, unordered_map<int, int>> &paths, unordered_set<int> &idols, int &air, int
// start_point,
//              int &cur, int &ans) {
//     // 返回时更新
//     if (air <= 0) {
//         cur = 0;
//         air = total_air;
//         return;
//     }
//     if (!paths.count(start_point)) return;
//     for (auto &elem : paths[start_point]) {
//         if (air >= 2 * elem.second && idols.count(elem.first)) ++cur;
//         ans = cur > ans ? cur : ans;
//         air -= 2 * elem.second;
//         recover(paths, idols, air, elem.first, cur, ans);
//     }
// }

// int total;
// int points, tunnels;
// int start, end, air;
// int idol_num, idol_tmp;

// cin >> total;
// while (total) {
//     cin >> points >> tunnels;
//     unordered_map<int, unordered_map<int, int>> paths;
//     for (int i = 0; i != tunnels; ++i) {
//         cin >> start >> end >> air;
//         paths[start].insert({end, air});
//     }
//     cin >> idol_num;
//     unordered_set<int> idols(idol_num);
//     for (int i = 0; i != idol_num; ++i) {
//         cin >> idol_tmp;
//         idols.insert(idol_tmp);
//     }
//     cin >> total_air;
//     auto tmp_air = total_air;
//     // 处理完输入
//     int ans = 0, cur = 0;
//     recover(paths, idols, tmp_air, 0, cur, ans);
//     cout << ans << endl;
//     // 处理下一组输入
//     --total;
// }