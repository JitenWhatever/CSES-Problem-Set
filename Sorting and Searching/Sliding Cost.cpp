/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers. Your task is to calculate for each window of k elements, 
from left to right, the minimum total cost of making all elements equal.

You can increase or decrease each element with cost x 
where x is the difference between the new and the original value. The total cost is the sum of such costs.

Input

The first input line contains two integers n and k: the number of elements and the size of the window.

Then there are n integers x1,x2,…,xn: the contents of the array.

Output

Output n−k+1 values: the costs.

Constraints
1≤k≤n≤2⋅105
1≤xi≤109
Example

Input:
8 3
2 4 3 5 8 1 2 1

Output:
2 2 5 7 7 1
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
    int n, k; cin>>n>>k;
    int a[n];
    for(int index = 0; index < n; ++index) {
        cin>>a[index];
    }

    index_set st;
    for(int index = 0; index < k; ++index) {
        st.insert(a[index]);
    }

    ll prev_median = *st.find_by_order((k + 1)/2 - 1);
    ll cost = 0;
    for(int index = 0; index < k; ++index) {
        cost += abs(a[index] - prev_median); 
    }
    cout<<cost;

    for(int index = 0; index < n - k; ++index) {
        st.erase(st.find_by_order(st.order_of_key(a[index])));

        st.insert(a[index + k]);

        ll median = *st.find_by_order((k + 1)/2 - 1);
        cost += abs(median - a[index + k]) - abs(prev_median - a[index]);
        
        if((int)(k&1) == 0) {
            cost -= (median - prev_median);
        }
        prev_median = median;
        cout<<" "<<cost;
    }

    return 0;
}