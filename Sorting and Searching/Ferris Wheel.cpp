/*
Time limit: 1.00 s Memory limit: 512 MB
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. 
You know the weight of every child.

What is the minimum number of gondolas needed for the children?

Input

The first input line contains two integers n and x: the number of children and the maximum allowed weight.

The next line contains n integers p1,p2,…,pn: the weight of each child.

Output

Print one integer: the minimum number of gondolas.

Constraints
    1≤n≤2⋅10^5
    1≤x≤10^9
    1≤pi≤x
Example

Input:
4 10
7 2 3 9

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    ll n, x; cin>>n>>x;
    vector<ll> v(n);
    ll result = 0;

    for(int index = 0; index < n; ++index) {
        cin>>v[index];
    }

   sort(v.begin(), v.end());
   for(int index_i = 0, index_j = n - 1; index_i < index_j; ++index_i, --index_j) {
        while(index_i < index_j && v[index_i] + v[index_j] > x) {
            --index_j;
        }

        if(index_i >= index_j) {
            break;
        }

        ++result;
    }
    cout<<n - result;

    return 0;
}