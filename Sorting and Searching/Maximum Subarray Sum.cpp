/*
Time limit: 1.00 s Memory limit: 512 MB
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print one integer: the maximum subarray sum.

Constraints
1≤n≤2⋅10^5
−109≤xi≤10^9
Example

Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n, x, maxSoFar = INT_MIN, maxSum = INT_MIN;
    cin>>n;
    while(n--) {
        cin>>x;
        maxSoFar = max(maxSoFar + x, x);
        maxSum = max(maxSum, maxSoFar);
    }

    cout<<maxSum<<"\n";
    return 0;
}