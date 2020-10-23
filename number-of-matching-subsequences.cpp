#include <bits/stdc++.h>

using namespace std;

int numMatchingSubseq(string S, vector<string>& words) {
    vector<vector<int>> alpha(26);
    for(int i=0; i<S.length(); i++)
        alpha[S[i]-'a'].push_back(i);

    int count=0;

    for(const string& w : words) {
        int x=-1;
        bool found=true;

        for(char c:w) {
            auto i=upper_bound(alpha[c-'a'].begin(), alpha[c-'a'].end(), x);
            if(i==alpha[c-'a'].end()) found=false;
            else x=*i;
        }

        if(found) count++;
    }
    return count;
}