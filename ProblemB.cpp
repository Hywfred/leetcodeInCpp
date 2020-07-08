#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argv, char *args[]) {
    int num;
    string left, equal, right;
    int factor;
    while (cin >> num, num > 0) {
        unordered_map<string, int> inDeg;
        unordered_map<string, int> outDeg;
        unordered_map<string, unordered_map<string, int>> hash;
        unordered_map<string, unordered_map<string, int>> pre_record;
        // 初始化每个单位的出度 入度
        for (int i = 0; i != num; ++i) {
            cin >> left;
            inDeg[left] = 0;
            outDeg[left] = 0;
        }
        // 存储该组所有数据
        for (int i = 0; i != num - 1; ++i) {
            cin >> left >> equal >> factor >> right;
            hash[left].insert({right, factor});
            pre_record[right].insert({left, factor});
            ++outDeg[left], ++inDeg[right];
        }
        // 调整每个点的出度入度 直到不大于 1
        while (true) {
            // 结束标志
            bool over = true;
            // 出度大于 1
            for (auto &elem : outDeg) {
                // 所有出度大于 1 的进行处理
                if (elem.second > 1) {
                    over = false;
                    auto next = hash[elem.first].begin();
                    auto pre = next++;
                    while (next != hash[elem.first].end()) {
                        if (pre->second < next->second) {
                            // 更新新连接
                            hash[pre->first].insert({next->first, next->second / pre->second});
                            pre_record[next->first].insert({pre->first, pre->second});
                            ++outDeg[pre->first];  // 更新出度 入度
                            // 更新旧连接
                            pre_record[next->first].erase(elem.first);
                            hash[elem.first].erase(next++);
                        } else {
                            hash[next->first].insert({pre->first, pre->second / next->second});
                            pre_record[pre->first].insert({next->first, next->second});
                            ++outDeg[next->first];
                            pre_record[pre->first].erase(elem.first);
                            hash[elem.first].erase(pre++);
                            ++next;
                        }
                        --outDeg[elem.first];  // 更新出度
                    }
                }
            }
            // 入度大于 1
            for (auto &elem : inDeg) {
                // 所有入度大于 1 的进行处理
                if (elem.second > 1) {
                    over = false;
                    auto next = pre_record[elem.first].begin();
                    auto pre = next++;
                    while (next != pre_record[elem.first].end()) {
                        auto pre_fact = hash[pre->first][elem.first];
                        auto next_fact = hash[next->first][elem.first];
                        if (pre_fact > next_fact) {
                            // 更新新连接
                            hash[pre->first].insert({next->first, pre_fact / next_fact});
                            pre_record[next->first].insert({pre->first, pre->second});
                            ++inDeg[next->first];  // 更新next入度
                            //更新旧连接
                            hash[pre->first].erase(elem.first);
                            pre_record[elem.first].erase(pre++);
                            ++next;
                        } else {
                            hash[next->first].insert({pre->first, next_fact / pre_fact});
                            pre_record[pre->first].insert({next->first, next->second});
                            ++inDeg[pre->first];
                            hash[next->first].erase(elem.first);
                            pre_record[elem.first].erase(next++);
                        }
                        --inDeg[elem.first];  // 更新入度
                    }
                }
            }
            if (over) break;
        }
        // 找到入度为 0 的
        string ans = "1";
        for (auto &elem : inDeg) {
            // 入度为 0
            if (!elem.second) {
                auto tmp = elem.first;
                auto last_factor = 1;
                while (outDeg[tmp]) {
                    last_factor *= hash[tmp].begin()->second;
                    ans += tmp + " = " + to_string(last_factor);
                    tmp = hash[tmp].begin()->first;
                }
                ans += tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
