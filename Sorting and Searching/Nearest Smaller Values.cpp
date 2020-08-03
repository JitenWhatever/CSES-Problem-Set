/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, 
your task is to find for each array position the nearest position to its left having a smaller value.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print n integers: for each array position the nearest position with a smaller value. 
If there is no such position, print 0.

Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n; cin>>n;
    ll a[n];
    stack<ll> st;
    for(int index = 0; index < n; index++) {
        cin>>a[index];
    }

    for(int index = 0; index < n; index++) {
        
        while(!st.empty() && a[st.top()] >= a[index] ) {
            st.pop();
        }

        if(!st.empty()) {
            cout<<st.top() + 1<<" ";
        }
        else {
            cout<<"0"<<" ";
        }

        st.push(index);
    }
    return 0;
}