#include <bits/stdc++.h>

using namespace std;

int totalFruit(vector<int>& tree) {
    if(tree.size()<=2) return tree.size();
    int b1=tree[0];
    int i=1;
    while(i<tree.size() && tree[i]==b1) i++;
    if(i==tree.size()) return i;
    int b2=tree[i];
    int s=0, b1e=i-1, b2e=i;
    int maxSize=++i;
    for(; i<tree.size(); i++) {
        if(tree[i]==b1)
            b1e=i;
        else if(tree[i]==b2)
            b2e=i;
        else {
            if(b1e<b2e) {
                maxSize=max<int>(maxSize, b2e-s+1);
                s=b1e+1;
                b1=tree[i];
                b1e=i;
            } else {
                maxSize=max<int>(maxSize, b1e-s+1);
                s=b2e+1;
                b2=tree[i];
                b2e=i;
            }
            cout<<endl;
        }
    }
    return max<int>(maxSize, max<int>(b1e,b2e)-s+1);
}