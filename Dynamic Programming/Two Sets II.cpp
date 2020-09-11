/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}
Input

The only input line contains an integer n.

Output

Print the answer modulo 109+7.

Constraints
1≤n≤500
Example

Input:
7

Output:
4
*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long 
const int MOD = 1000000007;

int main() {
    int n; cin>>n;
    ll sum = n*(n + 1)/2;

    if(sum%2) {
        cout<<"0\n";
        return 0;
    }
    sum = sum/2;
    vector<vector<ll>> dp(n, vector<ll>(sum + 1, 0)); // no. of ways to make sum x using first i coins;

    dp[0][0] = 1;

    for (int num = 1; num < n; ++num) {
        for (int amount = 0; amount <= sum; amount++) {
            dp[num][amount] += dp[num - 1][amount];
            if (amount - num >= 0) {
	            dp[num][amount] = (dp[num][amount]%MOD + dp[num - 1][amount - num]%MOD)%MOD;
            }

            dp[num][amount] %= MOD; 
        }
    }

    cout<<dp[n - 1][sum]<<"\n";

    return 0;
}

