/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, 
your task is to find the maximum sum of values in a contiguous subarray with length between a and b.

Input

The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅10^5
1≤a≤b≤n
−109≤xi≤10^9
Example

Input:
8 1 2
-1 3 -2 5 3 -5 2 2

Output:
8
*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef long long ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> index_set;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int main() {
    boost;
    int n, a, b; cin>>n>>a>>b;
    ll maxSum = LONG_MIN;
    ll prefix[n + 1];
    for(int index = 0; index < n; ++index) {
        cin>>prefix[index + 1];
        prefix[index + 1] += prefix[index];
    }

    set<array<ll, 2>> st;

    for(int index = 0; index <= n; index++) {
        if(index >= a) {
            st.insert({prefix[index - a], index - a});
        }
        if(st.size()) {
            maxSum = max(prefix[index] - (*st.begin())[0], maxSum);
        }

        if(index >= b) {
            st.erase({prefix[index - b], index - b});
        }
    }

    cout<<maxSum<<"\n";
    return 0;
}