#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> stack;
    if (nums.empty()) return stack;
    vector<int> answer(nums.size(), 0);
    int i = 0; bool looped = false;
    while (true) {
        if (!looped)
            stack.push_back(i);
        if (i==nums.size()-1) {
            i = 0;
            looped = true;
        }
        else i++;
        if (i == stack.back() && looped) {
            for (int x : stack) answer[x] = -1;
            break;
        }
        while (!stack.empty() && nums[i] > nums[stack.back()]) {
            answer[stack.back()] = nums[i];
            stack.pop_back();
        }
    }
    return answer;
}

int main()
{
    vector<int> inp{ 1, 1, 1, 1, 1, 1 };
    vector<int> ans = nextGreaterElements(inp);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}