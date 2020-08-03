/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print three integers: the positions of the values. If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤5000
1≤x,ai≤10^9
Example

Input:
4 8
2 7 5 1

Output:
1 3 4
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, t; cin>>n>>t;
    array<ll, 2> a[n];
    for(int index = 0; index < n; index++) {
        cin>>a[index][0];
        a[index][1] = index + 1;
    }

    sort(a, a + n);
    
    for(int index = 0; index < n - 2; index++) {
       
        if(index > 0 && a[index] == a[index - 1]) {
            continue;
        }
    
        int left = index + 1, right = n - 1;

        while(left < right) {
            ll sum = a[index][0] + a[left][0] + a[right][0];
            if(sum == t) {
                cout<<a[index][1]<<" "<<a[left][1]<<" "<<a[right][1]<<"\n";
                while(left < right && a[left] == a[left + 1]) {
                    ++left;
                }
                while(left < right && a[right] == a[right - 1]) {
                    --right;
                }
                ++left;
                --right;
            return 0;   
            }
            else if(sum < t) {
                ++left;
            }
            else {
                --right;
            }           
        }
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}
