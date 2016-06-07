//
//  LRUCache.h
//  LeetCode
//
//  Created by Jerome on 6/7/16.
//  Copyright © 2016 Jerome. All rights reserved.
//

#ifndef LRUCache_h
#define LRUCache_h

#include "DataStructure.h"

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        m_cap = capacity;
    }
    
    void touch(int key) {
        auto it = mymap[key].second;
        int val = mymap[key].first;
        used.erase(it);
        used.push_front(key);
        mymap[key] = {val, used.begin()};
    }
    
    int get(int key) {
        if (mymap.find(key)==mymap.end()) return -1;
        else {
            touch(key);
            return mymap[key].first;
        }
    }
    
    void set(int key, int value) {
        if (mymap.find(key)==mymap.end()) {
            if (used.size()==m_cap) {
                int key1 = used.back();
                mymap.erase(key1);
                used.pop_back();
            }
            used.push_front(key);
            mymap[key] = {value, used.begin()};
        }
        else {
            touch(key);
            mymap[key].first = value;
        }
    }
    
    list<int> used;
    unordered_map<int, pair<int, list<int>::iterator>> mymap;
    int m_cap;
};

#endif /* LRUCache_h */
