#pragma once

#include <utility>
#include <list>
#include <unordered_map>


class LRUCache {
public:

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end()){//key不存在
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);//最近使用，置前
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash.find(key);
        if(it == hash.end()){//key不存在
            cache.insert(cache.begin(), std::make_pair(key, value));
            hash[key] = cache.begin();
            if(cache.size() > cap){//超过容量
                hash.erase(cache.back().first);//在map中删掉
                cache.pop_back();//在list中删掉
            }
        }
        else{
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);//最近使用，置前
        }
    }

private:
    int cap;
    std::list< std::pair<int,int> > cache;//使用链表存储数据
    std::unordered_map<int, std::list< std::pair<int,int> >::iterator> hash;//使用哈希存储key对应链表指针
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
