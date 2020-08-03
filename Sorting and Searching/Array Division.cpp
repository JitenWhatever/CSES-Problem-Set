/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

Input

The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.

The next line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print one integer: the maximum sum in a subarray in the optimal division.

Constraints
1≤n≤2⋅10^5
1≤k≤n
1≤xi≤10^9
Example

Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. 
The largest sum is the last sum 8.
*/


#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
int a[MAX];

bool canPartition(ll mid,  int n, int K) { 
    ll count = 0; 
    ll sum = 0; 
    for (int i = 0; i < n; i++) { 

        if (a[i] > mid) 
            return false; 

        sum += a[i]; 

        if (sum > mid) { 
            count++; 
            sum = a[i]; 
        } 
    } 
    count++; 
  
    if (count <= K) {
        return true; 
    }

    return false; 
} 

int main(){
    boost;
    int n, k; cin>>n>>k;
    ll sum = 0, result = 0;
    for(int index = 0; index < n; ++index) {
        cin>>a[index];
        sum += a[index];
    }

    ll low = 1, high = sum;

    while(low <= high) {
        ll mid = low + (high - low)/2;

        if(canPartition(mid, n, k)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout<<result<<"\n";
    return 0;
}