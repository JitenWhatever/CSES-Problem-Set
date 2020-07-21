/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to count for k=1,2,…,n 
the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.

Input

The only input line contains an integer n.

Output

Print n integers: the results.

Constraints
1≤n≤10000
Example

Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n; cin>>n;
    for(int k = 1; k <= n; ++k) {
        ll totalPosition = k*k;
        ll totalPositionToPlace = totalPosition*(totalPosition - 1)/2; // one attack other vice versa

        if(k > 2) {
            totalPositionToPlace -= 4*(k - 1)*(k - 2); // attacking places 
        }

        cout<<totalPositionToPlace<<"\n";
    }
    return 0;
}
