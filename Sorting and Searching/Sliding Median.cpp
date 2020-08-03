/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers. Your task is to calculate the median of each window of k elements, 
from left to right.

The median is the middle element when the elements are sorted. 
If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.

Input

The first input line contains two integers n and k: the number of elements and the size of the window.

Then there are n integers x1,x2,…,xn: the contents of the array.

Output

Print n−k+1 values: the medians.

Constraints
1≤k≤n≤2⋅10^5
1≤xi≤10^9
Example

Input:
8 3
2 4 3 5 8 1 2 1

Output:
3 4 5 5 2 1
*/


#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

// priority_queue<int> maxHeap;
// priority_queue<int, vector<int>, greater<int>> minHeap;

set<array<int, 2>> maxHeap, minHeap;

void balance() {
    if (maxHeap.size() > minHeap.size() + 1) {
        array<int, 2> num = *maxHeap.rbegin();
        maxHeap.erase(num);
        minHeap.insert(num);
    } 
    else if (maxHeap.size() < minHeap.size()) {
        array<int, 2> num = *minHeap.begin();
        minHeap.erase(num);
        maxHeap.insert(num);
    }
}

int main() {
    boost;
    int n, k; cin>>n>>k;
    int a[n];
    for(int index = 0; index < n; index++) {
        cin>>a[index];
    }

    for(int index = 0; index < n; index++) {
        if(maxHeap.size() == 0 || (*maxHeap.rbegin())[0] >= a[index]) {
            maxHeap.insert({a[index], index});
        }
        else {
            minHeap.insert({a[index], index});
        }

        balance();

        if(index - k + 1 >= 0) {
            if(maxHeap.size() == minHeap.size()) {
                int median = min((*maxHeap.rbegin())[0],  (*minHeap.begin())[0]);
                cout<<median<<" ";
            }
            else {
                cout<<(*maxHeap.rbegin())[0]<<" ";
            }

            int remove  = a[index - k + 1];
            if(remove <= (*maxHeap.rbegin())[0]) {
                maxHeap.erase({remove, index - k +1});
            }
            else {
                minHeap.erase({remove, index - k +1});
            }

            balance();
        }
    }
    maxHeap.clear();
    minHeap.clear();
    return 0;
}

