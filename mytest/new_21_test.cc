#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, new_21) {
    Solution s;
    auto ans = s.new21Game(10, 1, 10);
    cout << ans << endl;
    EXPECT_TRUE(ans - 1.0 < 1e-5) << ans << endl;

    ans = s.new21Game(6, 1, 10);
    cout << ans << endl;
    EXPECT_TRUE(ans - 0.6 < 1e-5) << ans << endl;

    ans = s.new21Game(21, 17, 10);
    cout << ans << endl;
    EXPECT_TRUE(ans - 0.73278 < 1e-5) << ans << endl;
}