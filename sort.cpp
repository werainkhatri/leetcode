#include <bits/stdc++.h>

using namespace std;

int numMatchingSubseq(string S, vector<string>& words) {
    int slen=S.length(); int count=0;
    for(int i=0; i<words.size(); i++) {
        string w=words[i];
        short wi=w.length();
        int si=slen;
        if(wi>slen) continue;
        while(si>=0 && wi>=0) {
            if(w[wi]==S[si]) wi--;
            si--;
        }
        if(wi==-1) count++;
    }
    return count;
}

int main() {
    
    return 0;
}