/*
Time limit: 1.00 s Memory limit: 512 MB
You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:
what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 109+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?
Input

The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

After this, there are m lines describing the flights. Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.

You may assume that there is a route from Syrjälä to Lehmälä.

Output

Print four integers according to the problem statement.

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
Example

Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3

Output:
5 2 1 2
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll INF = 1e17;
const ll MOD = 1e9 + 7;

int n, m;

vector<vector<pll>> graph;
vector<vector<ll>> minGraph;
vector<ll> dist;
vector<bool> visi;
vector<ll> dp;


void dfsWays(int u) {

    dp[u] = u == n - 1 ? 1 : 0;

    visi[u] = 1;

    for(int v : minGraph[u]) {
        if(!visi[v]) {
            dfsWays(v);
        }
        dp[u] = (dp[u]%MOD + dp[v]%MOD)%MOD;
    }
}

void dfsMax(int u) {

    dp[u] = u == n - 1 ? 1 : -1e9;

    visi[u] = true;

    for(ll v : minGraph[u]) {
        if(!visi[v]) {
            dfsMax(v);
        }
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

void dfsMin(int u) {

    dp[u] = u == n - 1 ? 1 : 1e9;

    visi[u] = true;

    for(int v : minGraph[u]) {
        if(!visi[v]) {
            dfsMin(v);
        }
        dp[u] = min(dp[u], 1 + dp[v]);
    }
}

int main() {
    cin>>n>>m;

    graph = vector<vector<pll>>(n);
    for(int edge = 0; edge < m; ++edge) {
        ll u, v, w; cin>>u>>v>>w;
        --u, --v;
        graph[u].push_back({v, w});
    }

    dist = vector<ll>(n, INF);
    dist[0] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> minHeap;
    minHeap.push({0, 0});


    while(!minHeap.empty()) {
        ll u = minHeap.top().second;
        ll d = minHeap.top().first;
        minHeap.pop();
        
        if(dist[u] < d) {
            continue;
        }

        for(pll v : graph[u]) {
            if(dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                minHeap.push({dist[v.first], v.first});
            }
        }
    }

    cout<<dist[n - 1];
    
    minGraph = vector<vector<ll>>(n);

    for(ll  u = 0; u < n; u++) {
        for(pll v : graph[u]) {
            if(dist[u] + v.second == dist[v.first]) {
                minGraph[u].push_back(v.first);
            }
        }
    }

    dp = vector<ll>(n);
    visi = vector<bool>(n);
    dfsWays(0);

    cout<<" "<<dp[0];

  
    visi = vector<bool>(n);

    dfsMin(0);
    cout<<" "<<dp[0] - 1;
   
    visi = vector<bool>(n);
    dfsMax(0);
    cout<<" "<<dp[0] - 1;

    return 0;
}