/**
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为
4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：
输入：["a==b","b==c","a==c"]
输出：true
示例 4：
输入：["a==b","b!=c","c==a"]
输出：false
示例 5：
输入：["c==c","b==d","x!=z"]
输出：true
提示：
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='
 */
#include <unordered_map>
#include <unordered_set>

#include "daily.h"

using namespace std;

int u_find(int x, vector<int> &v) {
    // 当前元素根所在下标
    int root = x;
    // 找到根
    while (v[root] >= 0) { root = v[root]; }
    // 路径压缩，使路径上所有顶点都指向根
    int i = x, j;
    while (i != root) {
        j = v[i];
        v[i] = root;
        i = j;
    }
    return root;
}

void union_by_height(int first, int second, vector<int> &v) {
    // 如果两者的根已经相等，则返回
    // 查找过程中，同时进行路径压缩，将本路径上的所有节点直接挂到根上
    int r1 = u_find(first, v), r2 = u_find(second, v);
    if (r1 == r2) return;
    if (v[r2] < v[r1])
        v[r1] = r2;  // 如果 r2 更深，则将 r1 挂到 r2 上
    else {
        if (v[r1] == v[r2]) --v[r1];
        v[r2] = r1;
    }
}

bool Solution::equationsPossible(vector<string> &equations) {
    vector<int> letters(26, -1);
    // 构建并查集
    for (auto &e : equations) {
        if (e[1] == '!') continue;
        union_by_height(e[0] - 'a', e[3] - 'a', letters);
    }
    //
    for (auto &e : equations) {
        if (e[1] == '=') continue;
        if (u_find(e[0] - 'a', letters) == u_find(e[3] - 'a', letters)) return false;
    }
    return true;
}