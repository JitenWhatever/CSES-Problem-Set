/*
Time limit: 1.00 s Memory limit: 512 MB
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Input

The first input line has an integer n: the number of coins.

The next line has n integers x1,x2,…,xn: the values of the coins.

Output

First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

Constraints
1≤n≤100
1≤xi≤1000
Example

Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    vector<int> coins(n);
    int sum = 0;
    for(int index = 0; index < n; ++index) {
        cin>>coins[index];
        sum += coins[index];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false)); // posiible to make sum x using first i coins;

    dp[0][0] = true;

    for (int index = 1; index <= n; ++index) {
        for (int amount = 0; amount <= sum; amount++) {
            dp[index][amount] = dp[index - 1][amount];
            if (amount - coins[index - 1] >= 0 && dp[index - 1][amount - coins[index - 1]]) {
	            dp[index][amount] = true;
            }
        }
    }

    set<int> st ; 
    for(int index = 1; index <= sum; ++index) {
        if(dp[n][index]) {
            st.insert(index);
        }
    }

    cout<<st.size()<<"\n";
    for(int num : st) {
        cout<<num<<" ";
    }

    return 0;
}

