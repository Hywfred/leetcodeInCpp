//
// Created by Hywfred on 2020/3/6.
//

#ifndef LEETCODEINCPP_FINDCONTINUOUSSEQUENCE_H
#define LEETCODEINCPP_FINDCONTINUOUSSEQUENCE_H

#include <vector>
using namespace std;

class FindContinuousSequence {

public:
	// 优化方案，求和没必要每次都重新求，设置一个sum变量实时记录滑动窗口的和即可。
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> result;
		int i = 1, j = 2;
		int s = 0;
		while (i <= target/2) {
			s = sum(i, j);
			if (s < target) {
				j++;
			} else if (s > target) {
				i++;
			} else {
				vector<int> tmp;
				for (int k = i; k <= j; ++k) {
					tmp.push_back(k);
				}
				result.push_back(tmp);
				j++;
			}
		}
		return result;
	}

	inline int sum(int a, int b) {
		int result = 0;
		while (a <= b) {
			result += a++;
		}
		return result;
	}
};

inline ostream &operator<<(ostream &os, const vector<vector<int>> &arr) {
	os << '[';
	for (int i = 0; i < arr.size(); ++i) {
		os << '[';
		for (int j = 0; j < arr[i].size(); ++j) {
			os << arr[i][j] << ',';
		}
		os << ']';
	}
	os << ']';
	return os;
}

#endif //LEETCODEINCPP_FINDCONTINUOUSSEQUENCE_H
