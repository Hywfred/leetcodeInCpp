//
// Created by Hywfred on 2020/3/9.
//

#ifndef LEETCODEINCPP_SORT_H
#define LEETCODEINCPP_SORT_H

#include <vector>

using namespace std;

class Sort {
public:
    /*
     * 冒泡排序
     */
    void Bubble(vector<int> &input) {
        int length = input.size();
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (input[i] > input[j]) {
                    int tmp = input[i];
                    input[i] = input[j];
                    input[j] = tmp;
                }
            }
        }
    }
};


#endif //LEETCODEINCPP_SORT_H
