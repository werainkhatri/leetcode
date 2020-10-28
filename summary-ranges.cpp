#include <bits/stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> out;
    if(nums.empty()) return out;
    int st=0, en=0;
    for(short i=1; i<nums.size(); i++) {
        if(nums[i]==nums[en]+1) en++;
        else {
            string ent;
            if(st==en) ent=to_string(nums[st]);
            else ent=to_string(nums[st])+"->"+to_string(nums[en]);
            out.push_back(ent);
            st=en+1;
            en++;
        }
    }
    string ent;
    if(st==en) ent=to_string(nums[st]);
    else ent=to_string(nums[st])+"->"+to_string(nums[en]);
    out.push_back(ent);
    return out;
}