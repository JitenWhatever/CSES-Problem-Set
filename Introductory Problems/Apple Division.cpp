/*
Time limit: 1.00 s Memory limit: 512 MB
There are n apples with known weights. 
Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

Input

The first input line has an integer n: the number of apples.

The next line has n integers p1,p2,…,pn: the weight of each apple.

Output

Print one integer: the minimum difference between the weights of the groups.

Constraints
1≤n≤20
1≤pi≤109
Example

Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n; cin>>n;
    vector<ll> v(n);
    ll sum = 0;    
    for(int index = 0; index < n; ++index) {
        cin>>v[index];
        sum += v[index];
    }

    ll res = 0;
    for(int bit = 0; bit < (1<<n); ++bit) {
        ll currentSum = 0;
        for(int index = 0; index < n; index++) {
            if(bit&(1<<index)) {
                currentSum += v[index];
            }
        }
        if(currentSum <= sum/2) {
            res = max(res, currentSum);
        }
    }

    cout<<sum - 2*res<<"\n";

    return 0;
}