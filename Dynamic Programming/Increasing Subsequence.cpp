/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e.,
the longest subsequence where every element is larger than the previous one.

A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.

Input

The first line contains an integer n: the size of the array.

After this there are n integers x1,x2,…,xn: the contents of the array.

Output

Print the length of the longest increasing subsequence.

Constraints
1≤n≤2⋅105
1≤xi≤10^9
Example

Input:
8
7 3 5 3 6 2 9 8

Output:
4
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin>>n;

    vector<int> nums;
    for(int index = 0; index < n; index++) {
        cin>>x;
        auto itr = lower_bound(nums.begin(), nums.end(), x);
        if(itr != nums.end()){
           *itr = x;
        }
        else {
            nums.push_back(x);
        }
    }

    cout<<nums.size()<<"\n";
    return 0;
}