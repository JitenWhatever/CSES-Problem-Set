/*
Time limit: 1.00 s Memory limit: 512 MB
There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, 
and their score increases by that number. Both players try to maximize their scores.

What is the maximum possible score for the first player when both players play optimally?

Input

The first input line contains an integer n: the size of the list.

The next line has n integers x1,x2,…,xn: the contents of the list.

Output

Print the maximum possible score for the first player.

Constraints
1≤n≤5000
−10^9≤xi≤10^9
Example

Input:
4
4 5 1 3

Output:
8
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX = 5001;
ll minmax(vector<int> points, int l, int r, vector<vector<ll>>& dp) {
    if(l > r) {
        return 0;
    }
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    if(l == r) {
        return points[l];
    }
    dp[l][r] = max(points[l] - minmax(points, l + 1, r, dp), points[r] - minmax(points, l, r - 1, dp));
    return dp[l][r] ;
}

int main() {

    int n; cin>>n;
    ll sum = 0;
    vector<int> points(n);
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    for(int index = 0; index < n; index++) {
        cin>>points[index];
        sum += points[index];
    }

    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if(l == r) {
                dp[l][r] = points[l];
            }
            else {
                dp[l][r] = max(points[l] - dp[l + 1][r], points[r] - dp[l][r - 1]);
            }
        }
    }

    // minmax(points, 0, n - 1, dp); // TLE for 5000



    cout<<(sum + dp[0][n - 1])/2<<"\n";
    return 0;
}