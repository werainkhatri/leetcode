#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int mindiff=INT_MAX;
    for(int i=0; i<arr.size()-1; i++) {
        int diff = arr[i+1]-arr[i];
        if(mindiff > diff) mindiff=diff;
    }
    for(int i=0; i<arr.size()-1; i++) {
        int diff = arr[i+1]-arr[i];
        if(mindiff == diff)
            result.push_back({arr[i],arr[i+1]});
    }
    return result;
}