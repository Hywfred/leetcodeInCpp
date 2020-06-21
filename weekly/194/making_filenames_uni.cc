#include <unordered_map>
#include <unordered_set>

#include "../weekly/headers/194.h"

using namespace std;

// https://leetcode-cn.com/contest/weekly-contest-194/problems/making-file-names-unique/
vector<string> getFolderNames(vector<string> &names) {
    int len = names.size();
    vector<string> ans;
    unordered_set<string> nameans;
    unordered_map<string, int> namemap;
    string name;
    for (int i = 0; i < len; ++i) {
        name = names[i];
        if (nameans.count(name)) {
            if (namemap[name]) {
                string tmp = name + "(" + to_string(namemap[name] + 1) + ")";
                ++namemap[name];
                name = tmp;
            } else {
                int j = 1;
                while (true) {
                    string tmp = name + "(" + to_string(j) + ")";
                    if (nameans.count(tmp)) {
                        ++j;
                        continue;
                    } else {
                        namemap[name] = j;
                        name = tmp;
                        break;
                    }
                }
            }
        }
        nameans.insert(name);
        ans.push_back(name);
    }
    return ans;
}