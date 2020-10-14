#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    if(nums.empty()) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    int i=0,f=nums.size()-1;
    int m=(f+i)/2;
    while(nums[m]!=target && i<=f) {
        if(target<nums[m]) f=m-1;
        else i=m+1;
        m=(f+i)/2;
    }
    if(i>f) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    i=m; f=m;
    while(i>=0 && nums[i]==target) {i--;}
    result.push_back(++i);
    while(f<nums.size() && nums[f]==target) {f++;}
    result.push_back(--f);
    return result;
}

int main() {
    int n,t;
    cin>>n>>t;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin>>nums[i];
    vector<int> res = searchRange(nums, t);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}