/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.

Input

The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,…,n.

After this, the input has m lines describing the edges. Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.

Output

If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. 
If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".

Constraints
1≤n≤2500
1≤m≤5000
1≤a,b≤n
−10^9≤c≤10^9
Example

Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
YES
1 2 4 1
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF=1e17;

int main(){
    ll n, m, u, v, w;
    cin>>n>>m;

    vector<vector<pair<ll, ll>>> graph(n);
    for(int edge = 0; edge < m; ++edge) {
        cin>>u>>v>>w;
        --u;
        --v;
        graph[u].push_back({v, w});
    }

    vector<ll> dist(n, INF);
    vector<int> par(n, -1);

    dist[0] = 0;

    vector<bool> visi(n, false);
    
    for(int k = 0; k < n; ++k) {
        for(int node = 0; node < n; ++node) {
            for(pair<ll, ll> nbr : graph[node]) {
                if(dist[node] + nbr.second < dist[nbr.first]) {
                    dist[nbr.first] = dist[node] + nbr.second ;
                    par[nbr.first] = node;
                    if(k == n - 1) {
                        cout<<"YES\n";

                        while(!visi[node]) {
                            visi[node] = true;
                            node = par[node];
                        }
                        vector<ll> path;
                        path.push_back(node);
                        while(path[0] != par[node]) {
                            node = par[node];
                            path.push_back(node);
                        }
                        path.push_back(path[0]);
                        reverse(path.begin(), path.end());
                        for(ll p : path) {
                            cout<<p + 1<<" ";
                        }
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"NO\n";
    return 0;
}

