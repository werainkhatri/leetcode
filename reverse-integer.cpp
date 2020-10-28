#include<bits/stdc++.h>

using namespace std;

int reverse(int x) {
    int rev=0;
    bool neg=false;
    if(x<0) {
        if(x==INT_MIN) return 0;
        neg=true;
    }
    x=abs(x);
    if(log10(x)>=9) {
        while(x>0) {
            if(rev>(INT_MAX/10)) return 0;
            rev=rev*10+x%10;
            x/=10;
        }
    } else {
        while(x>0) {
            rev=rev*10+x%10;
            x/=10;
        }
    }
    return rev*(neg?-1:1);
}
