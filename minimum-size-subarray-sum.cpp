#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int start=0, end=0, sum=nums[0], minSize=nums.size()+1;
    while(start<=end) {
        if(sum < s) {
            if(end == nums.size()-1) break;
            end++;
            sum+=nums[end];
        } else {
            minSize = min<int>(end-start+1, minSize);
            sum -= nums[start];
            start++;
        }
    }
    return minSize == nums.size() + 1 ? 0 : minSize;
}