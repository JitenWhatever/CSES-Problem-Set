/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20!=2432902008176640000 and it has 4 trailing zeros.

Input

The only input line has an integer n.

Output

Print the number of trailing zeros in n!.

Constraints
1≤n≤109
Example

Input:
20

Output:
4
*/


#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n; cin>>n;

    ll zeros = 0;

    for(ll num = 5; n / num >= 1; num *= 5) {
        zeros += (n / num);
    }

    cout<<zeros<<"\n";
    return 0;
}