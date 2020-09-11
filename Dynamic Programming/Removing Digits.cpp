/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an integer n. On each step, you may substract from it any one-digit number that appears in it.

How many steps are required to make the number equal to 0?

Input

The only input line has an integer n.

Output

Print one integer: the minimum number of steps.

Constraints
1≤n≤10^6
Example

Input:
27

Output:
5

Explanation: An optimal solution is 27→20→18→10→9→0.
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {

    int n; cin>>n;
    vector<ll> dp(n + 1, n + 1);
    dp[0] = 0;

    for(int num = 0; num <= n; num++) {
        for(char ch : to_string(num)) {
            dp[num] = min(dp[num], dp[num - (ch - '0')] + 1);
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}
