#include <bits/stdc++.h>

using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B) {
    // a is correct
    short num=A[0], countA=0;
    for(int i=1; i<A.size(); i++) {
        if(A[i]==num) continue;
        else if(B[i]==num) countA++;
        else {countA=SHRT_MAX; break;}
    }
    // b is correct
    short countB=0; num=B[0];
    for(int i=1; i<A.size(); i++) {
        if(B[i]==num) continue;
        else if(A[i]==num) countB++;
        else {countB=SHRT_MAX; break;}
    }
    // flip 1st and a is correct
    short countC=1; num=B[0];
    for(int i=1; i<A.size(); i++) {
        if(A[i]==num) continue;
        else if(B[i]==num) countC++;
        else {countC=SHRT_MAX; break;}
    }
    // flip 1st and b is correct
    short countD=1; num=A[0];
    for(int i=1; i<A.size(); i++) {
        if(B[i]==num) continue;
        else if(A[i]==num) countD++;
        else {countD=SHRT_MAX; break;}
    }
    short ans=min<short>(countA, min<short>(countB, min<short>(countC, countD)));
    return ans==SHRT_MAX?-1:ans;
}

int main() {
    
    return 0;
}