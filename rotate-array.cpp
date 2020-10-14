#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    k=nums.size() - k;
    for(int i=0; i<k; i++) {
        int n=*(nums.begin());
        nums.erase(nums.begin());
        nums.push_back(n);
    }
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin>>nums[i];
    rotate(nums, k);
    for (int i = 0; i < n; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}