#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int>& a) {
    stack<int> res;
    for(int i=0; i<a.size(); i++) {
        if(res.empty()) res.push(a[i]);
        else {
            if(res.top()>0 & a[i]<0) {
                bool add=true;
                while(!res.empty() && res.top()>0 & a[i]<0) {
                    if(res.top()==-a[i]) {
                        res.pop();
                        add=false;
                        break;
                    }
                    if(res.top()<-a[i]) {
                        res.pop();
                        add=true;
                    } else {
                        add=false;
                        break;
                    }
                }
                if(add) res.push(a[i]);
            } else res.push(a[i]);
        }
    }
    vector<int> ans(res.size());
    for(int i=res.size()-1; i>=0; i--) {
        ans[i]=res.top();
        res.pop();
    }
    return ans;
}

string vectortostring(vector<int> v) {
    string s="";
    for(int a:v) s+=to_string(a)+", ";
    s=s.substr(0, s.length()-2);
    return s;
}

int main() {
    vector<int> a1{10,2,-5}, a2{-2,-1,1,2}, a3{5,10,-5};
    cout<<vectortostring(asteroidCollision(a1))
        <<endl<<vectortostring(asteroidCollision(a2))
        <<endl<<vectortostring(asteroidCollision(a3))
        <<endl;
    return 0;
}