#include <bits/stdc++.h>

using namespace std;

int maxPower(string s) {
    short power=0, count=1;
    for(int i=1; i<s.length(); i++) {
        if(s[i]==s[i-1]) count++;
        else {
            power=power>count?power:count;
            count=1;
        }
    }
    power=max(power,count);
    return power;
}