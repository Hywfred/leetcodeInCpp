//
// Created by Hywfred on 2020/3/22.
//

#ifndef LEETCODEINCPP_HWINTERVIEW_H
#define LEETCODEINCPP_HWINTERVIEW_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> findSubstrings(string s, vector<string> &words) {
    vector<int> res;
    int len = words.size();
    if (!len) {
        return res;
    }
    int l = words[0].size();
    // 先对原始单词组排序
    sort(words.begin(), words.end());
    int sl = s.size();
    for (int i = 0; i < sl; ++i) {
        vector<string> tmp;
        // 从 i 开始取相同个数个单词
        if (i + len * l <= sl) {
            for (int j = 0; j < len; ++j) {
                string str = s.substr(i + j*l, l);
                tmp.push_back(str);
            }
            // 对取出的新单词组进行排序
            sort(tmp.begin(), tmp.end());
            // 比较排序后的单词是否都一样
            bool same = true;
            for (int j = 0; j < len; ++j) {
                if (tmp[j] != words[j]) {
                    same = false;
                }
            }
            if (same) {
                res.push_back(i);
            }
        }
    }
    return res;
}
#endif //LEETCODEINCPP_HWINTERVIEW_H
