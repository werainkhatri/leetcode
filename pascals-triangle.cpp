#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> tri;
    if(numRows==0) return tri;
    vector<int> first; first.push_back(1);
    tri.push_back(first);
    if(numRows==1) return tri;
    first.push_back(1);
    tri.push_back(first);
    if(numRows==2) return tri;
    for(int i=0; i<numRows-2; i++) {
        vector<int> prev=tri.back();
        vector<int> next;
        next.push_back(1);
        for(int j=0; j<prev.size()-1; j++) next.push_back(prev[j]+prev[j+1]);
        next.push_back(1);
        tri.push_back(next);
    }
    return tri;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> triangle = generate(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < triangle[i].size(); j++)
            cout<<triangle[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}