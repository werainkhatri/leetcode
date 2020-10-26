#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    short maxx=0, count=0, i=0;
    while(i<nums.size() && nums[i]==0) i++;
    if(i++==nums.size()) return 0;
    count=1;
    for(; i<nums.size(); i++) {
        if(nums[i]==1) count++;
        else if(count!=0) {
            maxx=max<int>(maxx,count);
            count=0;
        }
    }
    return max<int>(maxx,count);
}