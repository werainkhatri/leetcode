#include <bits/stdc++.h>

using namespace std;

void f(short c, vector<int>& H, vector<short>& memo) {
    if(c>=H.size()) return;
    if(memo[c]!=-1) return;
    f(c+2,H,memo);
    f(c+1,H,memo);
    memo[c]=max<short>(memo[c+1], memo[c+2]+H[c]);
}

int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    if(nums.size()==1) return nums[0];
    vector<short> memo(nums.size()+2,-1);
    memo[nums.size()]=0;
    memo[nums.size()+1]=0;
    f(0,nums,memo);
    return memo[0];
}

int main() {
    vector<int> houses{104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
    // Expected: 3157
    cout<<rob(houses);
    return 0;
}