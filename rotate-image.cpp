#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    short int n=matrix.size();
    for(short int i=0; i<n/2; i++) {
        for(short int j=0; j<(n-2*i)-1; j++) {
            swap(matrix[i][i+j], matrix[i+j][n-1-i]);
            swap(matrix[i][i+j], matrix[n-1-i][n-1-i-j]);
            swap(matrix[i][i+j], matrix[n-1-i-j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix1{
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
        };
    vector<vector<int>> matrix2{
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
        };
    rotate(matrix1);
    rotate(matrix2);
    cout<<"Matrix 1: n=5"<<endl;
    for(vector<int> x : matrix1) {
        for(int y : x)
            cout<<y<<" ";
        cout<<endl;
    }
    cout<<"Matrix 2: n=4"<<endl;
    for(vector<int> x : matrix2) {
        for(int y : x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}