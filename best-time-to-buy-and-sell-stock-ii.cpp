#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& p) {
    if(p.size()==1) return 0;
    if(p.size()==2) return max(p[1]-p[0],0);
    int buy=-1, profit=0;
    for(int i=0; i<p.size(); i++) {
        if(buy!=-1) {
            while(i<p.size() && p[i-1]<p[i]) i++;
            if(i==p.size()) profit+=p[p.size()-1]-p[buy];
            else profit+=p[--i]-p[buy];
            cout<<"sell"<<i<<endl;
            buy=-1;
        } else {
            while(i<p.size()-1 && p[i+1]<=p[i]) i++;
            cout<<"buy"<<i<<endl;
            buy=i;
        }
    }
    return profit;
}