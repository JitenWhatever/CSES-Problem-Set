/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print four integers: the positions of the values. If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤1000
1≤x,ai≤109
Example

Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7
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
    
    for(int index_i = 0; index_i < n - 3; index_i++) {
       
        if(index_i > 0 && a[index_i] == a[index_i - 1]) {
            continue;
        }

        for(int index_j = index_i + 1; index_j < n - 2; index_j++) {
            if(index_j > index_i + 1 && a[index_j] == a[index_j - 1]) {
                continue;
            }

            int left = index_j + 1, right = n - 1;

            while(left < right) {
                ll sum = a[index_i][0] + a[index_j][0] + a[left][0] + a[right][0];
                if(sum == t) {
                    cout<<a[index_i][1]<<" "<<a[index_j][1]<<" "<<a[left][1]<<" "<<a[right][1]<<"\n";
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
    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}
