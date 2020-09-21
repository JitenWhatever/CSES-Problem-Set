/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. 
However, you can only use the coupon once.

Input

The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Metsälä.

After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.

You can assume that it is always possible to get from Syrjälä to Metsälä.

Output

Print one integer: the price of the cheapest route from Syrjälä to Metsälä.

When you use the discount coupon for a flight whose price is x, its price becomes ⌊x/2⌋ (it is rounded down to an integer).

Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
Example

Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

Output:
2
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define ll long long

vector<vector<pair<ll, ll>>> graph, rGraph;
ll INF=1e17;

int main() {
    // fastio;

    ll n, m, u, v, w;
    cin>>n>>m;
   
    graph = vector<vector<pair<ll, ll>>>(n);
    rGraph = vector<vector<pair<ll, ll>>>(n);

    for(int edge = 0; edge < m; ++edge) {
        cin>>u>>v>>w;
        --u;
        --v;
        graph[u].push_back({v, w});
        rGraph[v].push_back({u, w});
    }

    vector<ll> dist1(n, INF), dist2(n, INF);
    
    priority_queue<pair<ll, ll>, vector <pair<ll, ll>> , greater<pair<ll, ll>> > minHeap;

    dist1[0] = 0;
    minHeap.push({0, 0});
    while(!minHeap.empty()) {
       
        u = minHeap.top().second;
        w = minHeap.top().first;
        minHeap.pop();
    
        if(dist1[u] < w) {
            continue;
        }

        for(pair<ll, ll> nbr : graph[u]) {
            if(dist1[nbr.first] > dist1[u] + nbr.second) {
                dist1[nbr.first] = dist1[u] + nbr.second;
                minHeap.push({dist1[nbr.first], nbr.first});
            }
        }
    }

   

    dist2[n - 1] = 0;
    minHeap.push({0, n - 1});
    while(!minHeap.empty()) {
        u = minHeap.top().second;
        w = minHeap.top().first;
        minHeap.pop();

        if(dist2[u] < w) {
            continue;
        }

        for(pair<ll, ll> nbr : rGraph[u]) {
            if(dist2[nbr.first] > dist2[u] + nbr.second) {
                dist2[nbr.first] = dist2[u] + nbr.second;
                minHeap.push({dist2[nbr.first], nbr.first});
            }
        }
    }

    ll result = INF;
    for(int node = 0; node < n; node++) {
        for(pair<ll, ll> nbr : graph[node]) {
            result = min(result, dist1[node] + dist2[nbr.first] + nbr.second/2);
        }
    }

    cout<<result<<"\n";
    return 0;
}