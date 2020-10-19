#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bitset<9> set9;
    // rows
    for(short i=0; i<9; i++) {
        for(short j=0; j<9; j++) {
            if(board[i][j]=='.') continue;
            short e=board[i][j]-'1';
            if(set9[e]==1) return false;
            set9.set(e);
        }
        set9.reset();
    }

    // columns
    for(short i=0; i<9; i++) {
        for(short j=0; j<9; j++) {
            if(board[j][i]=='.') continue;
            short e=board[j][i]-'1';
            if(set9[e]==1) return false;
            set9.set(e);
        }
        set9.reset();
    }

    // boxes
    for(short b=0; b<9; b++) {
        short c=(b%3)*3, r=(b/3)*3;
        for(short i=r; i<r+3; i++) {
            for(short j=c; j<c+3; j++) {
                if(board[j][i]=='.') continue;
                short e=board[j][i]-'1';
                if(set9[e]==1) return false;
                set9.set(e);
            }
        }
        set9.reset();
    }

    return true;
}

int main() {
    vector<vector<char>> table1{
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}
        };
    vector<vector<char>> table2{
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
        };
    cout<<isValidSudoku(table1)<<endl;
    cout<<isValidSudoku(table2)<<endl;
    return 0;
}