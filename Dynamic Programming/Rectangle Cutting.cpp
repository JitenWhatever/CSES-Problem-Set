/*
Time limit: 1.00 s Memory limit: 512 MB
Given an a×b rectangle, your task is to cut it into squares. 
On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. 
What is the minimum possible number of moves?

Input

The only input line has two integers a and b.

Output

Print one integer: the minimum number of moves.

Constraints
1≤a,b≤500
Example

Input:
3 5

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

    int H, W; cin>>H>>W;
    vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));

    for(int h = 1; h <= H; ++h) {
        for(int w = 1; w <= W; ++w) {
            if(h == w) {
                dp[h][w] = 0;
            }
            else {
                int minimumMoves = 1e9;
                for(int i = 1; i < w; ++i) {
                    minimumMoves = min(minimumMoves, 1 + dp[h][w - i] + dp[h][i]);
                }

               for(int i = 1; i < h; ++i) {
                    minimumMoves = min(minimumMoves, 1 + dp[h - i][w] + dp[i][w]);
                }
                
                dp[h][w] = minimumMoves;
            }
        }
    }

    cout<<dp[H][W]<<"\n";

    return 0;
}