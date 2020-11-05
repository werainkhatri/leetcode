#include <bits/stdc++.h>

using namespace std;

int minCostToMoveChips(vector<int>& p) {
    int odd=0, eve=0;
    for(int i=0; i<p.size(); i++) {
        if(p[i]%2==0) eve++;
        else odd++;
    }
    return min(odd,eve);
}