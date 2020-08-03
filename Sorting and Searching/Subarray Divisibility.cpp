/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, 
your task is to count the number of subarrays where the sum of values is divisible by n.

Input

The first input line has an integer n: the size of the array.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅10^5
−109≤ai≤10^9
Example

Input:
5
3 1 2 7 4

Output:
1
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n, x; cin>>n;
    ll result = 0;
    vector<ll> prefix(n + 1, 0), modulo(n, 0);
    for(int index = 0; index < n; index++) {
       cin>>x;
       prefix[index + 1] = prefix[index] + x;
    }

    for(ll sum : prefix) {
        modulo[(sum%n + n)%n]++;
    }

    for(ll mod : modulo) {
        result += mod*(mod - 1)/2;
    }
    cout<<result<<"\n";
    return 0;
}