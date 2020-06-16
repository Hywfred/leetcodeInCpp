/**
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
示例: 
你可以将以下二叉树：
    1
   / \
  2   3
     / \
    4   5
序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 */
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>

#include "daily.h"

using namespace std;

string Codec::serialize(TreeNode *root) {
    string ans;
    if (!root) return ans;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();
        if (!node) {
            ans += "null,";
            continue;
        }
        ans += to_string(node->val) + ",";
        nodes.push(node->left);
        nodes.push(node->right);
    }
    ans.pop_back();
    return ans;
}

TreeNode *generate_tree(const vector<string> &data, int pos) {
    if (pos > data.size() - 1) return nullptr;
    if (data[pos] == "null") return nullptr;
    TreeNode *root = new TreeNode(0);
    root->val = stoi(data[pos]);
    root->left = generate_tree(data, pos * 2 + 1);
    root->right = generate_tree(data, pos * 2 + 2);
    return root;
}

TreeNode *generate_tree(const vector<string> &data) {
    if (data.empty()) return nullptr;
    queue<TreeNode *> nodes;
    int idx = 0;
    TreeNode *root = new TreeNode(stoi(data[idx]));
    nodes.push(root);

    while (!nodes.empty()) {
        auto node = nodes.front();
        nodes.pop();
        if (++idx >= data.size()) break;
        if (!node) continue;
        // left
        auto next = data[idx];
        if (next != "null") {
            TreeNode *left = new TreeNode(stoi(next));
            node->left = left;
            nodes.push(left);
        }
        // right
        if (++idx >= data.size()) break;
        next = data[idx];
        if (next != "null") {
            TreeNode *right = new TreeNode(stoi(next));
            node->right = right;
            nodes.push(right);
        }
    }
    return root;
}

TreeNode *Codec::deserialize(string data) {
    TreeNode *ans = nullptr;
    if (data.empty()) return ans;
    vector<string> nodes;
    istringstream is(data);
    string tmp;
    while (getline(is, tmp, ',')) nodes.push_back(tmp);
    ans = generate_tree(nodes);
    return ans;
}