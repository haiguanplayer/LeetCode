#include <gtest/gtest.h>
#include <memory>
#include "../include/LRUCache.h"

using namespace std;
TEST(LRUCacheTest, get)
{
    shared_ptr<LRUCache> p = make_shared<LRUCache>();
    ASSERT_TRUE(p != nullptr);

    ASSERT_EQ(p->get(1), -1);
}

TEST(LRUCacheTest, put)
{
    shared_ptr<LRUCache> p = make_shared<LRUCache>();
    ASSERT_TRUE(p != nullptr);

    cache.put(1, 1);
    cache.put(2, 2);
    ASSERT_EQ(p->get(1), 1);
}
