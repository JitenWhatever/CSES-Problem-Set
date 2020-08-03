/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

Input

The first input line has two integers n and x: the array size and the target sum.

The second line has n integers a1,a2,…,an: the array values.

Output

Print two integers: the positions of the values. If there are several solutions, you may print any of them. 
If there are no solutions, print IMPOSSIBLE.

Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example

Input:
4 8
2 7 5 1

Output:
2 4
*/

#include<bits/stdc++.h>

using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n, x, sum; cin>>n>>sum;
    map<int, int> mp;
    for(int index = 0; index < n; ++index) {
        cin>>x;
        if(mp.find(sum - x) != mp.end()) {
            cout<<mp[sum - x]<<" "<<index + 1<<"\n";
            return 0;
        }
        mp[x] = index + 1;
    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}
