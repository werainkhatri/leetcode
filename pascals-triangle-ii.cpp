#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate() {
    vector<vector<int>> tri;
    vector<int> first; 
    first.push_back(1); tri.push_back(first);
    first.push_back(1); tri.push_back(first);
    return tri;
}

void increase(int row, vector<vector<int>>& pt) {
    for(int i=pt.size()-1; i<row; i++) {
        vector<int> prev=pt.back();
        vector<int> next;
        next.push_back(1);
        for(int j=0; j<prev.size()-1; j++) next.push_back(prev[j]+prev[j+1]);
        next.push_back(1);
        pt.push_back(next);
    }
}

int main() {
    vector<vector<int>> pt = generate();
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        if(n>=pt.size()) increase(n, pt);
        for (int j = 0; j < pt[n].size(); j++)
            cout<<pt[n][j]<<" ";
        cout<<endl;
    }
    return 0;
}