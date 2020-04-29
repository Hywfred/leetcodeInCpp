#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, find_in_mountain_array) {
    vector<int> input{1,2,3,4,5,3,1};
    MountainArray m(input);
    Solution s;
    auto ans = s.findInMountainArray(3, m);
    EXPECT_EQ(ans, 2);
    EXPECT_EQ(findMountainTop(m), 4);    
    input = {0,1,2,4,2,1};
    m.set(input);
    ans = s.findInMountainArray(3, m);
    EXPECT_EQ(ans, -1);
    EXPECT_EQ(findMountainTop(m), 3); 

    input = {1, 5, 2};
    m.set(input);
    ans = s.findInMountainArray(0, m);
    EXPECT_EQ(ans, -1);
    EXPECT_EQ(findMountainTop(m), 1); 
}