#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int s=nums[0];
    int f=nums[s];
    while(s!=f) {
        s=nums[s];
        f=nums[nums[f]];
    }
    s=0;
    while(s!=f) {s=nums[s]; f=nums[f];}
    return s;
}

int main() {
    vector<int> nums{1,2,3,4,5,6,5};
    cout << findDuplicate(nums) << endl;
    return 0;
}
