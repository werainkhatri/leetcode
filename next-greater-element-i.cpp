#include<bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> stack;
    if(nums2.empty())
        return stack;
    unordered_map<int, int> m;
    stack.push_back(nums2[0]);
    for(int i=1; i<nums2.size(); i++) {
        while(!stack.empty() && nums2[i] > stack.back()) {
            m[stack.back()] = nums2[i];
            stack.pop_back();
        }
        stack.push_back(nums2[i]);
    }
    vector<int> answer;
    for(int i=0; i<nums1.size(); i++)
        answer.push_back(m[nums1[i]]?m[nums1[i]]:-1);
    return answer;
}