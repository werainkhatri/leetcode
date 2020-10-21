#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& hist) {
    if(hist.size()==1) return hist[0];
    hist.push_back(0);
    int i=0;
    stack<int> s;
    int maxArea=0;
    while(i<(int)hist.size()) {
        if(s.empty() || hist[i]>=hist[s.top()]) s.push(i++);
        else {
            while(!s.empty() && hist[i]<hist[s.top()]) {
                int peak=hist[s.top()];
                s.pop();
                int sub=s.empty()?0:(s.top()+1);
                maxArea=max<int>(maxArea, peak*(i-sub));
            }
        }
    }
    while(!s.empty()) {
        int peak=hist[s.top()];
        s.pop();
        int sub=s.empty()?0:(s.top()+1);
        maxArea=max<int>(maxArea, peak*(i-sub));
    }
    return maxArea;
}

int main() {
	int n;
	cin>>n;
	vector<int> hist(n);
	for(int i=0; i<n; i++) cin>>hist[i];
	cout<<largestRectangleArea(hist)<<endl;
	return 0;
}
