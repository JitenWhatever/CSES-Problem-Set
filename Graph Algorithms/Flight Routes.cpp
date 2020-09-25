/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A route can visit the same city several times.

Note that there can be several routes with the same price and each of them should be considered (see the example).

Input

The first input line has three integers n, m, and k: the number of cities, the number of flights, and the parameter k. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Metsälä.

After this, the input has m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. All flights are one-way flights.

You may assume that there are at least k distinct routes from Syrjälä to Metsälä.

Output

Print k integers: the prices of the k cheapest routes sorted according to their prices.

Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
1≤k≤10
Example

Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1

Output:
4 4 7

Explanation: The cheapest routes are 1→3→4 (price 4), 1→2→3→4 (price 4) and 1→2→4 (price 7).
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll INF=1e17;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<array<ll, 2>> graph[n];
    for(int edge = 0; edge < m; edge++) {
        ll u, v, w;
        cin>>u>>v>>w;
        --u;
        --v;
        graph[u].push_back({v, w});
    }

    vector<ll> dist[n];
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> minHeap;

    minHeap.push({0, 0});
    while(!minHeap.empty()) {
        array<ll, 2> u = minHeap.top();
        minHeap.pop();
        if((ll)dist[u[1]].size() >= k) {
            continue;
        }
        dist[u[1]].push_back(u[0]);
        for(array<ll, 2> v : graph[u[1]]) {
            minHeap.push({u[0] + v[1], v[0]});
        }
    }

    for(int i = 0; i < k; ++i) {
        cout<<dist[n - 1][i]<<" ";
    }
    return 0;
}