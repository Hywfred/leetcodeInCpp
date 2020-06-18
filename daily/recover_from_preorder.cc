/**
我们从二叉树的根节点 root 开始进行深度优先搜索。
在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为
D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。 如果节点只有一个子节点，那么保证该子节点为左子节点。
给出遍历输出 S，还原树并返回其根节点 root。
示例 1：
输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：
输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：
输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
提示：
原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。
 */
#include <string>
#include <unordered_map>

#include "daily.h"

using namespace std;

TreeNode *Solution::recoverFromPreorder(string S) {
    TreeNode *root = nullptr;
    int left = S.size() - 1, right = left;
    stack<pair<TreeNode *, int>> nodes;
    int top_level = 0, cur_level;
    while (true) {
        // 解析数字和所在的深度
        // 解析数字
        int val = 0;  // 当前值
        int times = 1;
        while (left >= 0 && S[left] != '-') {
            val += (S[left] - '0') * times;
            times *= 10;
            --left;
        }
        // 解析深度
        right = left;
        while (left - 1 >= 0 && S[--left] == '-') {}
        cur_level = right - left;  // 当前深度
        // 创建节点
        TreeNode *node = new TreeNode(val);
        // 如果 cur_level >= top_level，入栈
        if (cur_level >= top_level) {
            nodes.push({node, cur_level});
        } else {
            // 左子树
            auto left = nodes.top().first;
            nodes.pop();
            node->left = left;
            // 右子树
            if (!nodes.empty()) {
                auto right = nodes.top().first;
                if (nodes.top().second == cur_level + 1) {
                    nodes.pop();
                    node->right = right;
                }
            }
            // 将根结点入栈
            nodes.push({node, cur_level});
        }
        // 如果深度为 0，则表明找到根结点，退出
        if (!cur_level) {
            root = node;
            break;
        }
        right = left;  // 更新 right
        top_level = nodes.top().second;
    }
    return root;
}