/*
Time limit: 1.00 s Memory limit: 512 MB
There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.

Input

The first input line has two longegers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n, and city 1 is Syrjälä.

After that, there are m lines describing the flight connections. Each line has three longegers a, b and c: a flight begins at city a, ends at city b, and its price is c. 
Each flight is a one-way flight.

You can assume that it is possible to travel from Syrjälä to all other cities.

Output

Prlong n longegers: the shortest route lengths from Syrjälä to cities 1,2,…,n.

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
Example

Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);


int main() {
    fastio;
    long n, m, u, v, w;
    cin>>n>>m;
    vector<vector<pair<long, long>>> graph(n + 1);
    priority_queue<pair<long, long>, vector <pair<long, long>> , greater<pair<long, long>> > minheap; 
    vector<long> dist(n + 1, LONG_MAX);

    for(long edge = 0; edge < m; ++edge) {
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    dist[1] = 0;
    minheap.push({0, 1});
    while(!minheap.empty()) {
        u = minheap.top().second;
        long d = minheap.top().first;
        minheap.pop();
       if(d > dist[u]) {
           continue;
       }
        for(pair<long, long> node : graph[u]) {
            v = node.first;
            w = node.second;
            if(dist[v] >= dist[u] + w) {
                dist[v] = dist[u] + w;
                minheap.push({dist[v], v});
            }
        }
    }
    
    for(long node = 1; node <= n; ++node) {
        if(dist[node] == LONG_MAX) {
            cout<<"-1 ";
        }
        else {
            cout<<dist[node]<<" ";
        }
    }

    return 0;
}