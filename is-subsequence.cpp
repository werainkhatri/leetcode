#include<bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
    short si=s.length()-1,ti=t.length()-1;
    short count;
    while(si>=0&&ti>=0) {
        if(s[si]==t[ti]) si--;
        ti--;
    }
    if(si==-1) return true;
    return false;
}
