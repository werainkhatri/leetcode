#include <bits/stdc++.h>

using namespace std;

int contains(vector<int> v, int k) {
    for(int i=0; i<v.size(); i++) if(v[i]==k) return i;
    return -1;
}

int lengthOfLongestSubstring(string s) {
    vector<int> dict(128, -1);
    int res = 0, start = 0;
    for (int i = 0; i < s.size(); i++) {
        start = max(start, dict[s[i]]+1);
        res = max(res, i - start + 1);
        dict[s[i]] = i;
    }
    return res;
}