/**
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
示例：
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。
提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。
 */
#include "daily.h"

using namespace std;

int search_less_equal(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), i = n - 1, j = 0, res = 0;
    while (i >= 0 && j < n) {
        if (matrix[i][j] <= target) {
            res += i + 1;
            ++j;
        } else {
            --i;
        }
    }
    return res;
}

int kthSmallest(vector<vector<int>> &matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
        int mid = left + (right - left) / 2;
        int cnt = search_less_equal(matrix, mid);
        if (cnt < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

/**
 * 下面的解法时间复杂度比较高，可以利用 prioraty_queue
 * 或这二分法，二分法参考上面的代码
 */

/**
 * 思路：利用堆排序
 */

int dx[2]{1, 0};
int dy[2]{0, 1};  // dx和dy组合，比如(1, 0)代表右和下两个方向

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void siftDown(vector<vector<int>> &matrix) {
    int n = matrix.size();   // 一行元素个数
    int curx = 0, cury = 0;  // 代表当前索引
    int minx = curx, miny = cury;  // 这两个组成的下标代表当前三个节点(本节点，右节点，下节点)中的最小值
    while (true) {
        // 存在下节点
        if (cury + 1 < n && matrix[cury + 1][curx] < matrix[miny][minx]) {
            miny = cury + 1;
            minx = curx;
        }
        // 存在右节点
        if (curx + 1 < n && matrix[cury][curx + 1] < matrix[miny][minx]) {
            miny = cury;
            minx = curx + 1;
        }
        // 交换当前节点和最小节点的值
        if (curx != minx || cury != miny) {
            swap(matrix[cury][curx], matrix[miny][minx]);
            // 更新 curx  cury
            curx = minx, cury = miny;
        } else {
            return;
        }
    }
}

int Solution::kthSmallest(vector<vector<int>> &matrix, int k) {
    int ans;                                      // 结果
    int n = matrix.size();                        // 矩阵长宽
    if (k == n * n) return matrix[n - 1][n - 1];  // 如果求最大值直接返回，省去一部分操作
    int max = matrix[n - 1][n - 1] + 1;           // 设一个最大值上限，作为维护最小堆的辅助值
    while (true) {
        if (!--k) break;
        matrix[0][0] = max;
        siftDown(matrix);
    }
    return matrix[0][0];
}