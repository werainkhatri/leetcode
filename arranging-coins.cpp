#include <bits/stdc++.h>

using namespace std;

int arrangeCoins(int n) {
    for(int i=1; true; i++) {
        if(n>=i) n-=i;
        else return i-1;
    }
    return 0;
}