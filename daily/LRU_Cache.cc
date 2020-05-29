/**
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put
。 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。 写入数据 put(key, value) -
如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥 /
数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？
示例:
LRUCache cache = new LRUCache( 2 // 缓存容量 );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);     // 返回  1
cache.put(3, 3);  // 该操作会使得密钥 2 作废
cache.get(2);     // 返回 -1 (未找到)
cache.put(4, 4);  // 该操作会使得密钥 1 作废
cache.get(1);     // 返回 -1 (未找到)
cache.get(3);     // 返回  3
cache.get(4);     // 返回  4
*/
#include "daily.h"

using namespace std;

LRUCache::LRUCache(int capacity) : cap_(capacity) {}

int LRUCache::get(int key) {
    auto pos = kvs_.find(key);
    if (pos != kvs_.end()) {
        // 更新位置，提到最开始的位置
        // nodes_.splice(nodes_.begin(), nodes_, pos->second);
        auto p = *pos->second;
        nodes_.erase(pos->second);
        nodes_.push_front(p);
        kvs_[key] = nodes_.begin();
        // 返回对应的 value
        return pos->second->second;
    } else {
        return -1;
    }
}

void LRUCache::put(int key, int value) {
    auto pos = kvs_.find(key);
    auto size = kvs_.size();
    if (size >= cap_) {  // 如果此时缓冲区已满
        // 如果该键不存在
        if (pos == kvs_.end()) {
            // 删除最近最少使用的数据，然后插入数据
            auto k = nodes_.back().first;
            nodes_.pop_back();
            kvs_.erase(k);
            nodes_.push_front({key, value});
            kvs_[key] = nodes_.begin();
        } else {
            pos->second->second = value;
            // nodes_.splice(nodes_.begin(), nodes_, pos->second);
            auto p = *pos->second;
            nodes_.erase(pos->second);
            nodes_.push_front(p);
            kvs_[key] = nodes_.begin();
        }
    } else {
        if (pos != kvs_.end()) {  // 如果键存在
            auto it = kvs_[key];
            it->second = value;
            // nodes_.splice(nodes_.begin(), nodes_, it);
            auto p = *it;
            nodes_.erase(it);
            nodes_.push_front(p);
            kvs_[key] = nodes_.begin();
        } else {
            nodes_.push_front({key, value});
            kvs_[key] = nodes_.begin();
        }
    }
}