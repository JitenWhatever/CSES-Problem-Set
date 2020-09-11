/*
Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example

Input:
3 11
1 5 7

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, t; cin>>n>>t;
    vector<int> coins(n);
    for(int index = 0; index < n; ++index) {
        cin>>coins[index];
    }
    vector<int> dp(t + 1, t + 1);
    dp[0] = 0;
    for(int sum = 1; sum <= t; ++sum) {
        for(int coin : coins) {
            if(sum - coin >= 0) {
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }

    dp[t] == t + 1 ? cout<<"-1\n" : cout<<dp[t]<<"\n";
    return 0;
}


