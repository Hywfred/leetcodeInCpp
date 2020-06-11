/**
根据每日 气温
列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0
来代替。 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 */
#include <stack>

#include "daily.h"

using namespace std;

/**
 * 利用栈解决 而且是递减栈
 */
vector<int> Solution::dailyTemperatures(vector<int> &T) {
    auto len = T.size();
    vector<int> ans(len);
    // 栈存储 T 的下标，且为递减栈
    stack<int> s;
    s.push(0);
    int t;  // 栈顶元素
    for (int i = 1; i != len; ++i) {
        t = s.top();
        while (T[i] > T[t]) {
            ans[t] = i - t;
            s.pop();
            if (s.empty()) break;
            t = s.top();
        }
        s.push(i);
    }
    return ans;
}

// /**
//  * brute force 优化一
//  * 在比较过程中，相邻项可以判断的直接判断
//  * 还是超时
//  */
// vector<int> Solution::dailyTemperatures(vector<int> &T) {
//     auto len = T.size();
//     vector<int> ans(len);
//     for (int i = 0; i != len - 1; ++i) {
//         if (ans[i]) continue;
//         for (int j = i + 1; j != len; ++j) {
//             // 相邻项直接可以判断的先判断
//             if (T[j] > T[j - 1]) ans[j - 1] = 1;
//             if (T[j] > T[i]) {
//                 ans[i] = j - i;
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// /**
//  * brute force 超时
//  */
// vector<int> Solution::dailyTemperatures(vector<int> &T) {
//     auto len = T.size();
//     vector<int> ans(len);
//     for (int i = 0; i != len - 1; ++i) {
//         for (int j = i + 1; j != len; ++j) {
//             if (T[j] > T[i]) {
//                 ans[i] = j - i;
//                 break;
//             }
//         }
//     }
//     return ans;
// }