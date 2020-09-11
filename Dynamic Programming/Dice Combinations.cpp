/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. 
Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input

The only input line has an integer n.

Output

Print the number of ways modulo 109+7.

Constraints
1≤n≤10^6
Example

Input:
3

Output:
4
*/

#include<bits/stdc++.h>


using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
    int n; cin>>n;
    int coins[] = {1, 2, 3, 4, 5, 6};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int sum = 3; sum <= n; sum++) {
        for(int coin : coins) {        
            if(sum - coin >= 0) {
                dp[sum] = (dp[sum]%MOD + dp[sum - coin]%MOD)%MOD;
            }
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}