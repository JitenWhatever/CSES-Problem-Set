/*
Time limit: 1.00 s Memory limit: 512 MB
You are given the arrival and leaving times of n customers in a restaurant.

What was the maximum number of customers?

Input

The first input line has an integer n: the number of customers.

After this, there are n lines that describe the customers. 
Each line has two integers a and b: the arrival and leaving times of a customer.

You may assume that all arrival and leaving times are distinct.

Output

Print one integer: the maximum number of customers.

Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9
Example

Input:
3
5 8
2 4
3 9

Output:
2
*/
#include<bits/stdc++.h>

using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n, a, b; cin>>n;
    set<array<int, 2>> st;
    for(int index = 0; index < n; ++index) {
        cin>>a>>b;
        st.insert({a, 1});
        st.insert({b, -1});
    }

    int result = 0, soFar = 0;
    for(array<int, 2> a : st) {
        soFar += a[1];
        result = max(result, soFar);
    }

    cout<<result<<"\n";
    return 0;
}

