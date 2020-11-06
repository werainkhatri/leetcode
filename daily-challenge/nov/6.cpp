#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(vector<int>& nums, int t) {
    int len=nums.size();
    int l=1, h=nums.back();
    int mid=(l+h)/2;
    while(l<h) {
        int sum=0;
        for(int i=0; i<len; i++) {
            sum+=nums[i]/mid;
            sum+=(nums[i]%mid!=0);
        }
        if(sum>t) l=mid+1;
        else if(sum<=t) h=mid;
        mid=(l+h)/2;
    }
    return mid;
}