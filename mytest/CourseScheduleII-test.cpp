#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, course_schedule_ii) {
    vector<vector<int>> data = {{1, 0}};
    Solution s;
    auto ans = s.findOrder(2, data);
    vector<int> want = {0, 1};
    for (decltype(ans.size()) i = 0; i < ans.size(); ++i) {
        cout << "ans[" << to_string(i) << "]=" << ans[i] << endl;
        EXPECT_EQ(ans[i], want[i]);
    }

    data = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    ans = s.findOrder(4, data);
    want = {0, 1, 2, 3};
    decltype(want) want1 = {0, 2, 1, 3};
    for (decltype(ans.size()) i = 0; i < ans.size(); ++i) {
        if (ans[i] != want[i] && ans[i] != want1[i]) {
            cout << "ERROR: "
                 << "ans: " << ans[i] << ", wanted: " << want[i] << " or " << want1[i] << endl;
            break;
        }
    }
}