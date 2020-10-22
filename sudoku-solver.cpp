#include <bits/stdc++.h>

using namespace std;

// 36ms
// class Solution {
// private:
//     vector<vector<char>>* board;
    
//     bool possible(short r, short c, short n) {
//         (*board)[r][c]='0';
//         for(short i=0; i<9; i++)
//             if((*board)[r][i]-'0'==n)
//                 return false;
//         for(short i=0; i<9; i++)
//             if((*board)[i][c]-'0'==n)
//                 return false;
//         short bi=(r/3)*3, bj=(c/3)*3;
//         for(short i=0; i<3; i++) {
//             for(short j=0; j<3; j++) {
//                 if((*board)[bi+i][bj+j]-'0'==n)
//                     return false;
//             }
//         }
//         return true;
//     }
    
//     bool solve() {
//         for(short i=0; i<9; i++) {
//             for(short j=0; j<9; j++) {
//                 if((*board)[i][j]!='0') continue;
//                 for(int n=1; n<10; n++) {
//                     if(possible(i,j,n)) {
//                         (*board)[i][j]=(char)(n+'0');
//                         if(solve()) return true;
//                         (*board)[i][j]='0';
//                     }
//                 }
//                 return false;
//             }
//         }
//         return true;
//     }
    
// public:
//     void solveSudoku(vector<vector<char>>& inp) {
//         board=&inp;
//         for(short i=0; i<9; i++)
//             for(short j=0; j<9; j++)
//                 if(inp[i][j]=='.')
//                     inp[i][j]='0';
        
//         solve();
//     }
// };

// 28ms
class Solution {
private:
    vector<vector<char>>* board;
    
    vector<bitset<10>> boxes;
    short mini, minj;
    
    bool possible(short r, short c, short n) {
        for(short i=0; i<9; i++)
            if((*board)[r][i]-'0'==n)
                return false;
        for(short i=0; i<9; i++)
            if((*board)[i][c]-'0'==n)
                return false;
        return true;
    }
    
    bool solve() {
        for(short i=mini; i<9; i++) {
            for(short j=minj; j<9; j++) {
                if((*board)[i][j]!='0') continue;
                short bi=i/3*3+j/3;
                for(short n=1; n<10; n++) {
                    if(boxes[bi][n]) continue;
                    if(possible(i,j,n)) {
                        (*board)[i][j]=(char)(n+'0');
                        boxes[bi].set(n);
                        if(i<=mini&&j<=minj) {mini=i; minj=j;}
                        if(solve()) return true;
                        (*board)[i][j]='0';
                        boxes[bi].reset(n);
                        if(i==mini&&j==minj) minj++;
                    }
                }
                return false;
            }
        }
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& inp) {
        board=&inp;
        boxes.resize(9);
        for(short i=0; i<9; i++) {
            for(short j=0; j<9; j++) {
                if(inp[i][j]=='.') inp[i][j]='0';
                else boxes[(i/3)*3+j/3].set(inp[i][j]-'0');
            }
        }
        mini=0; minj=0;
        solve();
    }
};

