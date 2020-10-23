#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    if(mat.size()<=1 || mat[0].size()<=1) return mat;
    int m=mat.size(), n=mat[0].size();
    // vertically second last to first
    for(int i=m-2; i>=0; i--) {
        vector<int> diag;
        for(int y=i, x=0; y<m && x<n; y++, x++) {
            diag.push_back(mat[y][x]);
        }
        sort(diag.begin(), diag.end());
        for(int y=i, x=0; y<m && x<n; y++, x++) {
            mat[y][x]=diag.front();
            diag.erase(diag.begin());
        }
    }
    // horizontally second to second last
    for(int i=1; i<n-1; i++) {
        vector<int> diag;
        for(int y=0, x=i; y<m && x<n; y++, x++) {
            diag.push_back(mat[y][x]);
        }
        sort(diag.begin(), diag.end());
        for(int y=0, x=i; y<m && x<n; y++, x++) {
            mat[y][x]=diag.front();
            diag.erase(diag.begin());
        }
    }
    return mat;
}

int main() {
    
    return 0;
}