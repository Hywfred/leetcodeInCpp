/**
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:
输入: [2,1,5,6,2,3]
输出: 10
*/
#include "daily.h"

using namespace std;

/**
 * 题解
 */
int Solution::largestRectangleArea(vector<int> &heights) {
    heights.push_back(-1);
    //加入哨兵值，便于原先heights中的最后位置的值弹出
    //因为需要比最后一个值小的值，才能把最后一个值卡在
    //中间计算面积
    stack<int> stacks;
    stacks.push(-1);
    //栈压入哨兵值，便于heights打头的数组进行操作
    //压入-1为方便计算打头位置的面积
    int maxs = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (stacks.top() != -1 && heights[stacks.top()] > heights[i])
        //栈里面后面比前面大的时候才压入，相当于顺序压入，当
        //当前值比栈顶的值小的时候，相当于两个比栈顶小的值把
        //栈顶位置的数卡在中间，比如5，6，2，栈顶数为6
        //此时可以计算栈顶6围成的矩形面积
        {
            int nums = stacks.top();
            stacks.pop();
            maxs = max(maxs, heights[nums] * (i - stacks.top() - 1));
            //面积计算公式为当前下标值*(左右两边的坐标减去1)
        }
        stacks.push(i);
        //栈前面都为比当前值小的时候，无法将栈顶值卡在中间了
        //此时压入当前坐标
    }
    return maxs;
}