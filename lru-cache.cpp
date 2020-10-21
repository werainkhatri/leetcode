#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
    int cap;
    // technically a queue of keys
    list<int> lrucache;
    //            key     value, iterator for position in lru list
    unordered_map<int, pair<int, list<int>::iterator>> value;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int k) {
        auto find=value.find(k);
        if(find==value.end()) return -1;
        
        lrucache.erase(find->second.second);
        lrucache.push_back(k);
        find->second.second=prev(lrucache.end());
        
        return find->second.first;
    }
    
    void put(int k, int v) {
        auto find=value.find(k);
        if(find!=value.end()) { // if key exists
            find->second.first=v;
            
            lrucache.erase(find->second.second);
            lrucache.push_back(k);
            find->second.second=prev(lrucache.end());
            return;
        }
        if(lrucache.size()==cap) { // if cache is full
            int toremove=lrucache.front(); // get the front element in queue (Oldest accessed key)
            value.erase(value.find(toremove)); // remove it from value
            lrucache.pop_front(); // remove it from queue
        }
        // add the new value
        lrucache.push_back(k); // to queue
        value[k]={v,prev(lrucache.end())}; // and value
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */