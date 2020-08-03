/*
Time limit: 1.00 s Memory limit: 512 MB
There are n sticks with some lengths. 
Your task is to modify the sticks so that each stick has the same length.

You can either lengthen and shorten each stick. 
Both operations cost x where x is the difference between the new and original length.

What is the minimum total cost?

Input

The first input line contains an integer n: the number of sticks.

Then there are n integers: p1,p2,…,pn: the lengths of the sticks.

Output

Print one integer: the minimum total cost.

Constraints
1≤n≤2⋅10^5
1≤pi≤10^9
Example

Input:
5
2 3 1 5 2

Output:
5
*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n; cin>> n;
    ll totalCost = 0, tmpCost = 0;
    vector<int> v(n);
    for(int index = 0; index < n; ++index) {
        cin>>v[index];
    }

    sort(v.begin(), v.end());

    ll mid = v[n/2];

    for(ll num : v) {
        totalCost += abs(num - mid);
    }

    if(n%2 == 0) {
        mid = v[n/2 - 1];
        for(ll num : v) {
            tmpCost += abs(num - mid);
        }
        totalCost = min(totalCost, tmpCost);
    }
    
   

    cout<<totalCost<<"\n";
    return 0;
}

