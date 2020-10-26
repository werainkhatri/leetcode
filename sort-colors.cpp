#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n[3];
    memset(n,0,3*sizeof(int));
    for(int i=0; i<nums.size(); i++) n[nums[i]]++;
    n[1]+=n[0];
    n[2]+=n[1];
    for(int i=0; i<nums.size(); i++) {
        if(i<n[0]) nums[i]=0;
        else if(i<n[1]) nums[i]=1;
        else if(i<n[2]) nums[i]=2;
    }
}