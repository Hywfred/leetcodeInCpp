#include "daily.h"
#include "gtest/gtest.h"

using namespace std;

TEST(mytest, lru_cache) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    auto ans = cache.get(1);  // 返回  1
    EXPECT_EQ(ans, 1);
    cache.put(3, 3);     // 该操作会使得密钥 2 作废
    ans = cache.get(2);  // 返回 -1 (未找到)
    EXPECT_EQ(ans, -1);
    cache.put(4, 4);     // 该操作会使得密钥 1 作废
    ans = cache.get(1);  // 返回 -1 (未找到)
    EXPECT_EQ(ans, -1);
    ans = cache.get(3);  // 返回  3
    EXPECT_EQ(ans, 3);
    ans = cache.get(4);  // 返回  4
    EXPECT_EQ(ans, 4);

    LRUCache cahce1(2);
    ans = cahce1.get(2);
    EXPECT_EQ(ans, -1);
    cahce1.put(2, 6);
    ans = cahce1.get(1);
    EXPECT_EQ(ans, -1);
    cahce1.put(1, 5);
    cahce1.put(1, 2);
    ans = cahce1.get(1);
    EXPECT_EQ(ans, 2);
    ans = cahce1.get(2);
    EXPECT_EQ(ans, 6);
}