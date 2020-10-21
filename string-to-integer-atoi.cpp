#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    if(s.length()==0) return 0;
    // number
    long num=0;
    short slen=s.length();
    // trimming from front
    while(s[num]==' ') num++;
    s=s.substr(num);

    num=0;
    for(short i=0; i<s.length(); i++) {
        char c=s[i];
        if(num==0) {
            if(c=='-') {
                do {c=s[++i];} while(c=='0' && i<slen);
                if(c>'0' && c<='9') {
                    num=c-'0';
                    num=-num;
                } else break;
            } else if(c=='+') {
                do {c=s[++i];} while(c=='0' && i<slen);
                if(i==slen) break;
                else if(c>='0' && c<='9') num=c-'0';
                else break;
            } else if(c=='0') {
                do {c=s[++i];} while(c=='0' && i<slen);
                if(i==slen) break;
                else if(c>'0' && c<='9') num+=c-'0';
                else break;
            } else if(c>'0' && c<='9') {
                num=c-'0';
            } else break;
        } else if(c>='0' && c<='9') {
            c-='0';
            num*=10;
            num=(num<0)?(num-c):(num+c);
            if(num>INT_MAX) return INT_MAX;
            else if(num<INT_MIN) return INT_MIN;
        } else break;
    }
    return (int)num;
}

int main() {
    string s1="   -42";
    string s2="4193 with words";
    string s3="words and 987";
    string s4="-91283472332456";
    cout<<myAtoi(s1)<<endl;
    cout<<myAtoi(s2)<<endl;
    cout<<myAtoi(s3)<<endl;
    cout<<myAtoi(s4)<<endl;
    return 0;
}