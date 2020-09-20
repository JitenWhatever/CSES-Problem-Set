/*
Time limit: 1.00 s Memory limit: 512 MB
You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. 
You may go through a tunnel several times.

Your task is to walk from room 1 to room n. What is the maximum score you can get?

Input

The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,…,n.

Then, there are m lines describing the tunnels. Each line has three integers a, b and x: 
the tunnel starts at room a, ends at room b, and it increases your score by x. All tunnels are one-way tunnels.

You can assume that it is possible to get from room 1 to room n.

Output

Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print −1.

Constraints
1≤2500≤n
1≤5000≤m
1≤a,b≤n
−10^9≤x≤10^9
Example

Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Output:
5
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define ll long long

vector<vector<pair<int, int>>> graph;
vector<vector<int>> rGraph;
vector<bool> visi, rvisi;
const ll INF=1e17;
ll result, n, m;

void dfs(int u) {
    if(visi[u]) {
        return;
    }

    visi[u] = true;

    for(pair<int, int> v :  graph[u]) {
        dfs(v.first);
    }
}

void rdfs(int u) {
     if(rvisi[u]) {
        return;
    }

    rvisi[u] = true;

    for(int v :  rGraph[u]) {
        rdfs(v);
    }
}

int main() {
    fastio;
    cin>>n>>m;
    int u, v, w;
    graph = vector<vector<pair<int, int>>>(n);
    rGraph = vector<vector<int>>(n + 1);
    visi = vector<bool>(n, false);
    rvisi = vector<bool>(n, false);

    vector<ll> dist(n, -INF);
    for(int edge = 0; edge < m; ++edge) {
        cin>>u>>v>>w;
        --u;
        --v;
        graph[u].push_back({v, w});
        rGraph[v].push_back(u);
    }

    
    dfs(0);
    rdfs(n - 1);

    dist[0] = 0;
    bool change = false;
    for(int k = 0; k < n; ++k) {
        change = false;
        for(int node = 0; node < n; ++node) {
            for(pair<int, int> nbr : graph[node]) {
                if(dist[nbr.first] < dist[node] + nbr.second) {
                    if(visi[nbr.first] && rvisi[nbr.first]) {
                        change =true;
                    }
                    dist[nbr.first] = dist[node] + nbr.second;
                }
            }
        }
    }
    if(change) {
        cout<<"-1\n";
        return 0;
    }

    cout<<dist[n -  1]<<"\n";
    return 0;
}
