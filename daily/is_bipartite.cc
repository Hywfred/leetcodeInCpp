/**
 * https://leetcode-cn.com/problems/is-graph-bipartite/
给定一个无向图 graph，当这个图为二分图时返回 true。
如果我们能将一个图的节点集合分割成两个独立的子集 A 和 B，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B
集合，我们就将这个图称为二分图。 graph 将会以邻接表方式给出，graph[i] 表示图中与节点 i
相连的所有节点。每个节点都是一个在 0 到 graph.length-1 之间的整数。这图中没有自环和平行边： graph[i] 中不存在 i，并且
graph[i] 中没有重复的值。
示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释: 无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。
示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释:
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
注意:
graph 的长度范围为 [1, 100]。
graph[i] 中的元素的范围为 [0, graph.length - 1]。
graph[i] 不会包含 i 或者有重复的值。
图是无向的：如果 j 在 graph[i] 里边，那么 i 也会在 graph[j] 里边。
 */
#include <unordered_set>

#include "daily.h"

using namespace std;

bool Solution::isBipartite(vector<vector<int>> &graph) {
    int num = graph.size();
    unordered_set<int> A;
    unordered_set<int> B;
    vector<bool> visited(num);
    for (int i = 0; i < num; ++i) {
        // 设置访问标志，放置重复访问
        if (visited[i]) continue;
        visited[i] = true;
        // 将 i 放入 A，与 i 的连接点放入 B
        A.insert(i);
        for (auto &elem : graph[i]) B.insert(elem);
        while (true) {
            bool goon = false;
            // 处理 B 中的每个点
            for (auto &elem : B) {
                if (visited[elem]) continue;
                visited[elem] = true;
                for (auto &e : graph[elem]) {
                    if (B.count(e)) return false;  // 如果点 elem 对应的连接点已经存在于 B 则不可能构成二分图
                    A.insert(e);
                    goon = true;
                }
            }
            // 处理 A 中的每个点
            for (auto &elem : A) {
                if (visited[elem]) continue;
                visited[elem] = true;
                for (auto &e : graph[elem]) {
                    if (A.count(e)) return false;  // 如果点 elem 对应的连接点已经存在于 B 则不可能构成二分图
                    B.insert(e);
                    goon = true;
                }
            }
            if (!goon) break;
        }
    }
    return true;
}

// // 将 i 点的连接点放入 B 或者 A
// bool inB = true;
// for (auto &elem : graph[i]) {
//     if (B.count(elem)) {
//         inB = false;
//         break;
//     }
// }
// if (inB) {
//     for (auto &elem : graph[i]) B.insert(elem);
// } else {
//     for (auto &elem : graph[i]) A.insert(elem);
// }