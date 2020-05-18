#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, max_product) {
    vector<int> data{2, 3, -2, 4};
    Solution s;
    auto ans = s.maxProduct(data);
    cout << ans << endl;

    data = {-2, 0, -1};
    ans = s.maxProduct(data);
    cout << ans << endl;

    data = {2, 3, -2, 4, -2};
    ans = s.maxProduct(data);
    cout << ans << endl;
}