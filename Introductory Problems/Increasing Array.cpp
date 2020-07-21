/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

On each turn, you may increase the value of any element by one. What is the minimum number of turns required?

Input

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print the minimum number of turns.

Constraints
1≤n≤2⋅105
1≤xi≤109
Example

Input:
5
3 2 5 1 7

Output:
5
*/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {

    ll n; cin>>n;
    ll x, res = 0, large = 0;
    for(int index = 0; index < n; ++index) {
        cin>>x;
        large = max(x, large);

        res += (large - x); 
    }
    cout<<res;
    return 0;
}