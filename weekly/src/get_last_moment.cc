#include <algorithm>

#include "196.h"

using namespace std;

int getLastMoment(int n, vector<int> &left, vector<int> &right) {
    if (left.empty() && right.empty()) return 0;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    if (left.empty()) return n - right[0];
    if (right.empty()) return left[left.size() - 1];
    int left_max = left[left.size() - 1];
    int right_max = n - right[0];
    return left_max < right_max ? right_max : left_max;
}