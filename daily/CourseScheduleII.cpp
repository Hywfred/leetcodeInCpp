/**
现在你总共有 n 门课需要选，记为 0 到 n-1。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
示例 1:
输入: 2, [[1,0]]
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:
输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
说明:
输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:
这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于 Coursera 的精彩视频教程（21 分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。
 */
#include <queue>
#include <vector>

#include "daily.h"

using namespace std;

vector<int> Solution::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    // 4, [[1,0],[2,0],[3,1],[3,2]]
    queue<int> inDegZeros;  // 存储入度为 0 的节点
    vector<int> inDegs(numCourses);
    vector<int> ans;  // 存储结果序列
    // 统计所有节点的入度
    for (const auto &req : prerequisites) {
        ++inDegs[req.at(0)];
    }
    // 将所有入度为 0 的节点入队
    for (decltype(inDegs.size()) i = 0; i < numCourses; ++i) {
        if (!inDegs[i]) inDegZeros.push(i);
    }
    // 拓扑排序
    int count = 0;  // 统计当前输出的顶点数
    while (!inDegZeros.empty()) {
        int vtex = inDegZeros.front();  // 当前入度为 0 的节点
        inDegZeros.pop();
        ++count;              // 更新计数
        ans.push_back(vtex);  // 记录节点
        // 将以该节点为尾部的所有边删除
        for (const auto &req : prerequisites) {
            if (req[1] == vtex)
                // 如果以 vtex 为尾部的邻接点，入度减一后为 0，则继续将该节点入队
                if (!(--inDegs[req[0]])) inDegZeros.push(req[0]);
        }
    }
    if (count < numCourses) vector<int>().swap(ans);
    return ans;
}