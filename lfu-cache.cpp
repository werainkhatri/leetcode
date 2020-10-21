#include <bits/stdc++.h>

using namespace std;

// size of freqQ=N and of cache=N
// O(N) for finding key in cache
// O(N) for finding correct place for key in freqQ
// O(N)*O(N) = O(N^2)
class LFUCacheON2 {
private:
    int cap;
    // frequency queue
    //       key  frequency
    list<pair<int,int>> freqQ;
    
    // map       key      value  iterator
    unordered_map<int, pair<int, list<pair<int,int>>::iterator>> cache;
    
    int* access(unordered_map<int, pair<int, list<pair<int,int>>::iterator>>::iterator find) {
        pair<int,int> f=*(find->second.second);                 // get the pair
        freqQ.erase(find->second.second);                       // remove it from freqQ
        f.second++;                                             // increment the frequency
        for(auto i=freqQ.begin(); i!=freqQ.end(); i++) {        // put the pair in correct position
            if((*i).second > f.second) {
                find->second.second = freqQ.insert(i, f);
                return &(find->second.first);
            }
        }
        find->second.second = freqQ.insert(freqQ.end(), f);
        return &(find->second.first);
    }
    
public:
    LFUCacheON2(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto find=cache.find(key);
        if(find==cache.end()) return -1;
        return *access(find);
    }
    
    void put(int key, int value) {
        auto find=cache.find(key);
        if(find!=cache.end()) { // it exists
            *access(find)=value;
            return;
        }
        if(cap==0) return;
        // does not exists
        if(freqQ.size()==cap) { // if cap reached
            int keytoremove = freqQ.front().first; // get the pair
            freqQ.pop_front(); // remove it from frequency queue
            cache.erase(cache.find(keytoremove)); // remove from cache
        }
        // add the new key-value
        for(auto i=freqQ.begin(); i!=freqQ.end(); i++) {
            // insert the new key, frequency pair
            // reason for adding it at <2 is since it is recently accessed too.
            if((*i).second>=2) {
                cache[key]={value, freqQ.insert(i, {key, 1})};
                return;
            }
        }
        freqQ.push_back({key, 1});
        cache[key]={value, prev(freqQ.end())};
    }
};

// ##################################################################################

// for O(N log(N))
// find correct position using binary search
// O(N) * O(logN) -> O(N logN)
// but this cannot be done as binary search cannot be applied on list


// ##################################################################################
// for O(N)
// finding correct position should be linear
class LFUCacheON {
private:
    int cap;
    // vector of frequency queues
    //              key  frequency  
    vector<list<pair<int,int>>> freq;
    
    // minimum frequency in freq
    int minFreq=1;
    
	// number of elements in cache
    int elementCount=0;
    
    // map       key      value  iterator
    unordered_map<int, pair<int, list<pair<int,int>>::iterator>> cache;
    
	// accesses the key-value and increments frequency
    int* access(unordered_map<int, pair<int, list<pair<int,int>>::iterator>>::iterator find) {
        pair<int,int> f=*(find->second.second);                 // get the pair
        freq[f.second].erase(find->second.second);              // remove it from list in freq at f.second
        f.second++;                                             // increment the frequency
        freq[f.second].push_back(f);                            // push it back to list of its new freq
        find->second.second = prev(freq[f.second].end());       // add the iterator to cache
        if(minFreq==f.second-1 && freq[minFreq].empty())        // if the key with minimum freq and recency is removed
            minFreq++; // update minFreq
        return &(find->second.first);                           // return the pointer to value
    }
    
public:
    LFUCacheON(int capacity) {
        cap=capacity;
        freq.resize(10000);
    }
    
    int get(int key) {
        auto find=cache.find(key); // find element
        if(find==cache.end()) return -1; // if doesn't exists
        return *access(find); // else access it and return value
    }
    
    void put(int key, int value) {
        auto find=cache.find(key); // find element
        if(find!=cache.end()) { // if it exists
            *access(find)=value; // access it, change it's value
            return; // and return
        }
        if(cap==0) return;
        // if it does not exists
        if(elementCount==cap) { // if cap reached
            int keytoremove = freq[minFreq].front().first; // get the least frequent least recent pair
            freq[minFreq].pop_front(); // remove it from frequency queue
            cache.erase(cache.find(keytoremove)); // remove from cache
            elementCount--; // decrement count as a pair is removed
        }
		// if cap is reached (key is removed) or not, add the key-value pair
        freq[1].push_back({key, 1}); // adds the new key-frequency pair to frequency 1 list (since accessed once)
        cache[key]={value, prev(freq[1].end())}; // add the value-iterator pair to cache
        minFreq=1; // make minFreq 1 as new key is added
        elementCount++; // increment as new element is added
    }
};

int main() {
    
    return 0;
}