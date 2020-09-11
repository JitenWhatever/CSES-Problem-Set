/*
Time limit: 1.00 s Memory limit: 512 MB
Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square 
where you only can move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. 
Each line has n characters: . denotes an empty cell, and * denotes a trap.

Output

Print the number of paths modulo 109+7.

Constraints
1≤n≤1000
Example

Input:
4
....
.*..
...*
*...

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll dp[1001][1001];
int main() {
    int n; cin>>n;
    string grid[n];
    for(int index = 0; index < n; index++) {
        cin>>grid[index];
    }
    
    for(int index_i = 0; index_i < n; index_i++) {
        for(int index_j = 0; index_j < n; index_j++) {
            if(index_i == 0 && index_j == 0) {
                dp[index_i][index_j] = (grid[index_i][index_j] == '.' ? 1 : 0);
                continue;
            }
            if(index_i) {
                dp[index_i][index_j] += dp[index_i - 1][index_j]; 
            }
            if(index_j) {
                dp[index_i][index_j] += dp[index_i][index_j - 1]; 
            }
            
            dp[index_i][index_j] %= MOD;

            if(grid[index_i][index_j] == '*') {
                dp[index_i][index_j] = 0;
            }

            
        }
    }

    cout<<dp[n - 1][n - 1];    
    return 0;
}