#include <bits/stdc++.h>

using namespace std;

int hIndex(vector<int>& c) {
    if(c.size()==0) return 0;
    sort(c.begin(), c.end());
    for(int i=c.size()-1; i>=0; i--)
        if((c.size()-i)>c[i]) {
            return c.size()-i-1;
        } else if((c.size()-i)==c[i])
            return c[i];
    return c.size();
}

int main() {
    vector<int> c{1,2,3,4,5,6,8,9,10};
    cout<<hIndex(c)<<endl;
    return 0;
}