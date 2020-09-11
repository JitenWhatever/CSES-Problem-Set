/*
Time limit: 1.00 s Memory limit: 512 MB
You know that an array has n integers between 1 and m, and the difference between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, 
your task is to count the number of arrays that match the description.

Input

The first input line has two integers n and m: the array size and the upper bound for each value.

The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.

Output

Print one integer: the number of arrays modulo 109+7.

Constraints
1≤n≤10^5
1≤m≤100
0≤xi≤m
Example

Input:
3 5
2 0 2

Output:
3

Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 1e5;
const int MOD = 1000000007;
int nums[MAX];

int main() {
    int n, m; cin>>n>>m;
    for(int index = 0; index < n; index++) {
        cin>>nums[index + 1];
    }

    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));

    for(int index = 1; index <=n ; index++) {
        for(int num = 1; num <= m; ++num) {
            if(index == 1) {

                if(nums[index] == 0 || nums[index] == num){
                    dp[index][num] = 1;
                }
                else {
                    dp[index][num] = 0;
                }
                continue;
            }

            if(nums[index] == 0 || nums[index] == num){
                    dp[index][num] = ((dp[index - 1][num - 1] + dp[index - 1][num])%MOD + dp[index - 1][num + 1])%MOD;
                }
            else {
                dp[index][num] = 0;
            }
        }
    }

    ll validArrays = 0;
    for(int num = 1; num <= m; ++num) {
        validArrays = (validArrays +  dp[n][num])%MOD;
    }

    cout<<validArrays<<"\n";

    return 0;
}
