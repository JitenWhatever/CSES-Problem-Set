/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65
*/



#include<bits/stdc++.h>

#define ll long long

using namespace std;

vector<bool> col(14), diag1(14), diag2(14);
vector<vector<bool>> board(8, vector<bool>(8));

ll totalWays = 0;

void helper(int r) {
    if(r == 8) {
        ++totalWays;
        return ;
    }

    for(int c = 0; c < 8; c++) {
        if(col[c] || diag1[r + c] || diag2[r - c + 7] || board[r][c]) {
            continue;
        }
        col[c] = diag1[r + c] = diag2[r - c + 7] = true;
        helper(r + 1);
        col[c] = diag1[r + c] = diag2[r - c + 7] = false;
    }
}

int main() {
    string s;

    for(int r = 0; r < 8; ++r) {
        cin>>s;
        for(int c = 0; c < 8; c++) {
            board[r][c] = (s[c] != '.');
        }
    }

    helper(0);

    cout<<totalWays<<"\n";
    return 0;
}