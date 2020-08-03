/*
Time limit: 1.00 s Memory limit: 512 MB
You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.

You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?

Input

The first input line contains an integer n: the number of cubes.

The next line contains n integers k1,k2,…,kn: the sizes of the cubes.

Output

Print one integer: the minimum number of towers.

Constraints
1≤n≤2⋅105
1≤ki≤109
Example

Input:
5
3 8 2 1 5

Output:
2
*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n, x; cin>>n;
    vector<int> v;
    for(int index = 0; index < n; ++index) {
        cin>>x;
        int d = upper_bound(v.begin(), v.end(), x) - v.begin();
        if(d < (int)v.size()) {
            v[d] = x;
        }
        else {
            v.push_back(x);
        }
    }
    for(int num : v) {
        cout<<num<<" ";
    }
    cout<<v.size();
    return 0;
}

