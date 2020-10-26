#include <bits/stdc++.h>

using namespace std;

int bagOfTokensScore(vector<int>& t, int P) {
    sort(t.begin(), t.end());
    int score=0, maxS=0;
    int b=0,e=t.size()-1;
    while(b<=e) {
        if(P>=t[b]) {
            P-=t[b];
            b++;
            score++;
            if(score>maxS) maxS=score;
        } else if(score>0) {
            P+=t[e];
            e--;
            score--;
        } else break;
    }
    return maxS;
}