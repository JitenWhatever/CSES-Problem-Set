/*
Time limit: 1.00 s Memory limit: 512 MB
Consider a money system consisting of n coins. Each coin has a positive integer value. 
Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example

Input:
3 9
2 3 5

Output:
8
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD 1000000007
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
const int MAX = 1e6;
ll dp[MAX + 1];

int main() {
    boost;
    int n, sum; cin>>n>>sum;
    int coins[n];
    for(int index = 0; index < n; index++) {
        cin>>coins[index];
    }
    dp[0] = 1;

    for(int t = 1; t <= sum; ++t) {
        for(int coin : coins) {
            if(t >= coin) {
                dp[t] = (dp[t] + dp[t - coin])%MOD;
            }
        }
    }

    cout<<dp[sum]<<"\n";
    return 0;
}