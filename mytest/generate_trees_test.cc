#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, generate_trees) {
    Solution s;
    auto ans = s.generateTrees(3);
    cout << endl;

    ans = s.generateTrees(8);
    cout << endl;
}