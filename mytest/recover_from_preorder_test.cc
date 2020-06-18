#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, recover_from_preorder) {
    Solution s;
    auto ans = s.recoverFromPreorder("1-2--3--4-5--6--7");
    LevelTraversal(ans);
    cout << endl;

    ans = s.recoverFromPreorder("1-2--3---4-5--6---7");
    LevelTraversal(ans);
    cout << endl;

    ans = s.recoverFromPreorder("1-401--349---90--88");
    LevelTraversal(ans);
    cout << endl;
}