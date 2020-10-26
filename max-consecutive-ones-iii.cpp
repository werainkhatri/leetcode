#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int>& A, int K) {
    if(K==0) {
        short maxx=0, count=0, i=0;
        while(i<A.size() && A[i]==0) i++;
        if(i++==A.size()) return 0;
        count=1;
        for(; i<A.size(); i++) {
            if(A[i]==1) count++;
            else if(count!=0) {
                maxx=max<int>(maxx,count);
                count=0;
            }
        }
        return max<int>(maxx,count);
    }
    queue<int> zpos;
    short maxx=0, start=0;
    for(int i=0; i<A.size(); i++) {
        if(A[i]==0) {
            if(zpos.size()>=K) {
                maxx=max<int>(maxx, i-start);
                start=zpos.front()+1;
                zpos.pop();
            }
            zpos.push(i);
        }
    }
    start=A.size()-start;
    return maxx>start?maxx:start;
}