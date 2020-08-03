/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n positive integers, your task is to count the number of subarrays having sum x.

Input

The first input line has two integers n and x: the size of the array and the target sum x.

The next line has n integers a1,a2,…,an: the contents of the array.

Output

Print one integer: the required number of subarrays.

Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example

Input:
5 7
2 4 1 2 7

Output:
3
*/


#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n, t, x, sum = 0; cin>>n>>t;
    map<ll, ll> hash;
    ll result = 0;
    hash[0] = 1;
    for(int index = 0; index < n; index++) {
        cin>>x;
        sum += x;

        if(hash.find(sum - t) != hash.end()) { 
            result += hash[sum - t];
        }

        hash[sum]++;
    }

    cout<<result<<"\n";
    return 0;
}

