/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to calculate the number of bit strings of length n.

For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input

The only input line has an integer n.

Output

Print the result modulo 109+7.

Constraints
1≤n≤106
Example

Input:
3

Output:
8
*/

#include<bits/stdc++.h>

#define ll long long 

using namespace std;

ll MOD = 1e9 + 7;

int main() {
    ll n; cin>>n;

    ll ans = 2;
    for(ll index = 1; index < n; ++index) {
        ans = (ans%MOD * 2%MOD)%MOD;
    }

    cout<<ans<<"\n";
    return 0;
}