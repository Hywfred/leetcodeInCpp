#pragma once
#ifndef _DAILY_H
#define _DAILY_H

#include <climits>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "ListNode.h"
#include "TreeNode.h"

/**
 *  This is the MountainArray's API interface.
 *  You should not implement it, or speculate about its implementation
 */
class MountainArray {
  public:
    MountainArray(const std::vector<int> &arr) : m_arr(arr) {}
    int get(int index);
    int length();
    void set(const std::vector<int> &arr);

  private:
    std::vector<int> m_arr;
};

class Solution {
  public:
    Solution() : pre(LONG_MIN) {}

    void set_pre() { pre = LONG_MIN; }

    int strStr(std::string haystack, std::string needle);

    std::vector<int> rightSideView(TreeNode *root);

    // 硬币 20.04.23
    int waysToChange(int n);

    // 数组中的逆序对  20.04.24
    int reversePairs(std::vector<int> &nums);

    // 全排列 20.04.25
    std::vector<std::vector<int>> permute(std::vector<int> &nums);

    // 合并 K 个排序链表 20.04.26
    ListNode *mergeKLists(std::vector<ListNode *> &lists);

    // 搜索旋转排序数组 20.04.27
    int search(std::vector<int> &nums, int target);

    // 数组中数字出现的次数 20.04.28
    std::vector<int> singleNumbers(std::vector<int> &nums);

    // 山脉数组 20.04.29
    int findInMountainArray(int target, MountainArray &mountainArr);

    // 快乐数 20.04.30
    bool isHappy(int n);

    // 合并两个有序链表 20.05.01
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

    // 无重复字符的最长子串 20.05.02
    int lengthOfLongestSubstring(std::string s);

    // 最大子序和 20.05.03
    int maxSubArray(std::vector<int> &nums);

    // 跳跃游戏 II 20.05.04
    int jump(std::vector<int> &nums);

    // 验证二叉搜索树 20.05.05
    bool isValidBST(TreeNode *root);

    // 最低票价 20.05.06
    int mincostTickets(std::vector<int> &days, std::vector<int> &costs);

    // 另一棵树的子树 20.05.07
    bool isSubtree(TreeNode *s, TreeNode *t);

    // 最大正方形20.05.08
    int maximalSquare(std::vector<std::vector<char>> &matrix);

    // x 的平方根 20.05.09
    int mySqrt(int x);

    // 最近公共祖先 20.05.10
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

    // 实现 pow(x, n) 20.05.11
    double myPow(double x, long long n);

    // 二叉树的层序遍历 20.05.13
    std::vector<std::vector<int>> levelOrder(TreeNode *root);

    // 只出现一次的数字 20.05.14
    int singleNumberII(std::vector<int> &nums);

    // 和为 k 的子数组 20.05.15
    int subarraySum(std::vector<int> &nums, int k);

    // k 个一组翻转链表 20.05.16
    ListNode *reverseKGroup(ListNode *head, int k);

    // 课程表 II 20.05.17
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites);

    // 乘积最大子数组 20.05.18
    int maxProduct(std::vector<int> &nums);

    // 验证回文字符串 ii 20.05.19
    bool validPalindrome(std::string s);

    // 每个元音包含偶数次的最长子字符串 20.05.20
    int findTheLongestSubstring(std::string s);

    // 最长回文子串
    std::string longestPalindrome(std::string s);

    // 根据前序与中序遍历序列构建二叉树 20.05.22
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder);

    // 最小覆盖子串 20.05.23
    std::string minWindow(std::string s, std::string t);

    // 寻找两个正序数组的中位数
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2);
    // 寻找重复数 20.05.26
    int findDuplicate(std::vector<int> &nums);

    // 和可被 K 整除的子数组 20.05.27
    int subarraysDivByK(std::vector<int> &A, int K);

    // 字符串解码 20.05.28
    std::string decodeString(std::string s);

    // 打家劫舍 20.05.29
    int rob(std::vector<int> &nums);

    // 柱状图中最大的矩形面积 20.05.30
    int largestRectangleArea(std::vector<int> &heights);

    // 对称二叉树 20.05.31
    bool isSymmetric(TreeNode *root);
    bool iter_symmetric(TreeNode *root);

    // 拥有最多糖果的孩子 20.06.01
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies);

    // 求 1+2+...+n 20.0.02
    int sumNums(int n);
    int sumNums1(int n);
    int sumNums2(int n);

    // 新 21 点 20.06.03
    double new21Game(int N, int K, int W);

    // 除自身以外数组的乘积 20.06.04
    std::vector<int> productExceptSelf(std::vector<int> &nums);

    // 顺时针打印矩阵 20.06.05
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);

    // 最长连续序列 20.06.06
    int longestConsecutive(std::vector<int> &nums);

    // 单词接龙II 20.06.07
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord,
                                                      std::vector<std::string> &wordList);

    // 等式方程的可满足性 20.06.08
    bool equationsPossible(std::vector<std::string> &equations);

    // 把数字翻译成字符串 20.06.09
    int translateNum(int num);

    // 回文数 20.06.10
    bool isPalindrome(int x);

    // 每日温度 20.06.11
    std::vector<int> dailyTemperatures(std::vector<int> &T);

    // 三数之和 20.06.12
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

    // 爬楼梯 20.06.13
    int climbStairs(int n);

    // 转变数组后最接近目标值的数组和 20.06.14
    int findBestValue(std::vector<int> &arr, int target);

    // 最长公共前缀 20.06.14
    std::string longestCommonPrefix(std::vector<std::string> &strs);

    // 二叉树的序列化与反序列化 20.06.16

    // 最佳观光组合 20.06.17
    int maxScoreSightseeingPair(std::vector<int> &A);

    // 从先序遍历还原二叉树 20.06.18
    TreeNode *recoverFromPreorder(std::string S);

    // 验证回文串 20.06.19
    bool isPalindrome(std::string s);

    // 正则表达式匹配 20.06.20
    bool isMatch(std::string s, std::string p);

    // 二叉树中的最大路径和 20.06.21
    int maxPathSum(TreeNode *root);

    // 模式匹配 20.06.22
    bool patternMatching(std::string pattern, std::string value);

    // 二进制求和 20.06.23
    std::string addBinary(std::string a, std::string b);

    // 最接近的三数之和 20.06.24
    int threeSumClosest(std::vector<int> &nums, int target);

    // 单词拆分 20.06.25
    bool wordBreak(std::string s, std::vector<std::string> &wordDict);

    // 移除重复节点
    ListNode *removeDuplicateNodes(ListNode *head);

    // 缺失的第一个正数 20.06.27
    int firstMissingPositive(std::vector<int> &nums);

    // 长度最小的子数组 20.06.28
    int minSubArrayLen(int s, std::vector<int> &nums);

    // 数组中第 k 个最大元素
    int findKthLargest(std::vector<int> &nums, int k);

    // 用两个栈实现队列 20.06.30
    // 见类 CQueue

    // 最长重复子数组 20.07.01
    int findLength(std::vector<int> &A, std::vector<int> &B);

    // 有序矩阵中第 k 小的元素
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k);

    // 将有序数组转换为二叉搜索树 20.07.03
    TreeNode *sortedArrayToBST(std::vector<int> &nums);

    // 最长有效括号 20.07.04
    int longestValidParentheses(std::string s);

    // 通配符匹配 20.07.05
    bool isMatchII(std::string s, std::string p);

    // 不同路径 II 20.07.06
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid);

    // 路径总和 20.07.07
    bool hasPathSum(TreeNode *root, int sum);

    // 跳水板 20.07.08
    std::vector<int> divingBoard(int shorter, int longer, int k);

    // 回复空格 20.07.09
    int respace(std::vector<std::string> &dictionary, std::string sentence);

    // 最佳买卖股票的时机含了冷冻期 20.07.10
    int maxProfit(std::vector<int> &prices);

    // 计算右侧小于当前元素的个数 20.07.11
    std::vector<int> countSmaller(std::vector<int> &nums);

    // 地下城游戏 20.07.12
    int calculateMinimumHP(std::vector<std::vector<int>> &dungeon);

    // 两个数组的交集II 20.07.13
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2);

    // 三角形最小路径和 20.07.14
    int minimumTotal(std::vector<std::vector<int>> &triangle);

    // 不同的二叉搜索树 20.07.15
    int numTrees(int n);

    // 判断二分图 20.07.16
    bool isBipartite(std::vector<std::vector<int>> &graph);

    // 搜索插入位置 20.07.17
    int searchInsert(std::vector<int> &nums, int target);

    // 戳气球 20.07.19
    int maxCoins(std::vector<int> &nums);

    // 两数之和II - 输入有序数组 20.07.20
    std::vector<int> twoSum(std::vector<int> &numbers, int target);

    // 不同的二叉搜索树 II 20.07.21
    std::vector<TreeNode *> generateTrees(int n);

    // 旋转数组的最小数字 20.07.21
    int minArray(std::vector<int> &numbers);

    // 最小路径和 20.07.23
    int minPathSum(std::vector<std::vector<int>> &grid);

    // 分割数组的最大值 20.07.25
    int splitArray(std::vector<int> &nums, int m);

    // 矩阵中的最长递增路径 20.07.26

    // 判断子序列 20.07.27
    bool isSubsequence(std::string s, std::string t);

    // 二叉树的最大深度 20.07.28
    int maxDepth(TreeNode *root);

    // 寻宝 20.07.29
    int minimalSteps(std::vector<std::string> &maze);

    // 正数拆分 20.07.30
    int integerBreak(int n);

    // 魔术索引 20.07.31
    int findMagicIndex(std::vector<int> &nums);

    // 二叉树展开为链表 20.08.02
    void flatten(TreeNode *root);

    // 字符串相加 20.08.03
    std::string addStrings(std::string num1, std::string num2);

    // 回文对 20.08.06
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words);

  private:
    long pre;
};

class CQueue {
  public:
    CQueue() {}

    void appendTail(int value) { in_.push(value); }

    int deleteHead() {
        if (in_.empty() && out_.empty()) return -1;
        if (out_.empty()) trans();
        int tmp = out_.top();
        out_.pop();
        return tmp;
    }

  private:
    std::stack<int> in_;
    std::stack<int> out_;

    void trans() {
        while (!in_.empty()) {
            int tmp = in_.top();
            in_.pop();
            out_.push(tmp);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
class Codec {
  public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root);

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data);
};

int findMountainTop(MountainArray &m);

// 单词接龙II 题解
//用记忆来培养思维，而不是单纯记忆。
//讲东西时先抛开代码讲整体思路，然后再具体到代码讲细节。
//双端BFS构建整颗最短树，DFS找最短树中beginWord到endWord的路径，因为最短树层数就那么多，所以找到的路径一定是最短的。
//当beginSet中的一个单词在endSet中出现时，说明双端搜索相遇了。
//用双端搜索而不是单端，是因为双端更省时。
class Solution1 {
  private:
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> map;
    //用unordered_map是因为查找key的时间复杂度O(1),找到了key，对应的value就是树的下一层了。(vector<vector<string>>的查找就太慢了)，用map的key来存储原string,用value来存储原string所有的下一层string(wordSet中所有的只与原string相差一个字符的word)
  public:
    std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord,
                                                      std::vector<std::string> &wordList) {
        // BFS把找最短序列过程中的每一层的erase后的wordSet中的word们都统计出，包括相遇的那层的word们。然后用dfs去搜索
        //最短序列，因为只统计到相遇那一层，层数就那么多，所以dfs找到的序列层数一定是那么多，所以一定是最短序列。
        std::unordered_set<std::string> wordSet{wordList.begin(), wordList.end()};
        if (!wordSet.count(endWord)) return res;
        std::unordered_set<std::string> beginSet{beginWord};
        std::unordered_set<std::string> endSet{endWord};
        int flag1 = 0, flag2 = 0;  // flag1标记是否已经双端搜索相遇了
        while (!beginSet.empty()) {
            std::unordered_set<std::string> next;
            for (std::string word : beginSet) {  //单独建个循环统一删除
                wordSet.erase(word);
            }
            for (std::string word : beginSet) {
                for (int w = 0; w < word.size(); ++w) {
                    std::string tmp = word;
                    for (int i = 'a'; i <= 'z'; ++i) {
                        tmp[w] = i;
                        if (!wordSet.count(tmp)) continue;
                        if (!endSet.count(tmp))
                            next.emplace(tmp);
                        else
                            flag1 = 1;  // flag1 = 1，双端set搜索相遇了，在添加完这一整层的word后退出循环。
                        flag2 ? map[tmp].emplace_back(word) : map[word].emplace_back(tmp);
                    }
                }
            }
            if (flag1) break;
            beginSet = next;
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
                flag2 = !flag2;  //搜索方向取反，所以flag2标志也要取反，这样子构建的树是从上到下顺序构造的。
            }
        }
        std::vector<std::string> vec{beginWord};
        dfs(vec, beginWord, endWord);
        return res;
    }

    void dfs(std::vector<std::string> &vec, std::string beginWord, std::string endWord) {
        if (beginWord == endWord) {
            res.push_back(vec);
            return;
        }
        if (!map.count(beginWord)) return;
        //对于BFS出的哈希表，单层交给迭代，整棵树交给递归
        for (auto &temp : map[beginWord]) {
            vec.emplace_back(temp);
            dfs(vec, temp, endWord);
            vec.pop_back();
        }
    }
};

// 最小栈 20.05.12
class MinStack {
  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x);

    void pop();

    int top();

    int getMin();

  private:
    std::stack<int> m_data;
    std::multiset<int> order;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
  public:
    using val_iter_type = std::list<std::pair<int, int>>::iterator;
    LRUCache(int capacity);

    int get(int key);

    void put(int key, int value);

    std::unordered_map<int, val_iter_type> kvs_;
    std::list<std::pair<int, int>> nodes_;
    int cap_;
};

#endif  // _DAILY_H
