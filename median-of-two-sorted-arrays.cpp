#include <bits/stdc++.h>

using namespace std;

double nextNum(vector<int>& M, vector<int>& N, short& m, short& n) {
    if(m==M.size()) return N[n++];
    else if(n==N.size()) return M[m++];
    else if(M[m]>N[n]) return N[n++];
    else return M[m++];
}

double findMedianSortedArrays(vector<int>& M, vector<int>& N) {
    short m=0, n=0;
    int sum=M.size()+N.size();
    if(sum%2!=0) {
        sum--;
        while((m+n)<sum/2) nextNum(M,N,m,n);
        return nextNum(M,N,m,n);
    } else {
        sum-=2;
        while((m+n)<sum/2) nextNum(M,N,m,n);
        return (nextNum(M,N,m,n)+nextNum(M,N,m,n))/2;
    }
}

int main() {
    vector<int> arr1{1,3,5,7,9,11,13,15};
    vector<int> arr2{2,4,6,8,10,12,14,16};
    cout<<findMedianSortedArrays(arr1, arr2)<<endl;
    return 0;
}