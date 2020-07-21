/*
Time limit: 1.00 s Memory limit: 512 MB
You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

Input

The first input line contains an integer n.

The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

Output

Print the missing number.

Constraints
2≤n≤2⋅105
Example

Input:
5
2 3 1 5

Output:
4
*/

#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {

    ll n, x, sum = 0;
    cin>>n;
    for(int index = 0; index < n - 1; ++index) {
        cin>>x;
        sum += x;
    }

    cout<<n*(n + 1)/2 - sum;
    return 0;
}



