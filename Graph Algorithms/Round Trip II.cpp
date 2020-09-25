/*
Time limit: 1.00 s Memory limit: 512 MB
Byteland has n cities and m flight connections. 
Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. 
Every intermediate city on the route has to be distinct.

Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n.

Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight connection from city a to city b. 
All connections are one-way flights from a city to another city.

Output

First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const ll MAX=1e5;

vector<ll> graph[MAX];
vector<ll> par, visi;

void dfs(int u) {

    if(visi[u] == 2) {
        return ;
    }

    visi[u] = 1;
    
    for(int v : graph[u]) {
        if(visi[v] == 1) {
            par[v] = u;
            vector<ll> path;
            path.push_back(u);
            while(path[0] != par[u]) {
                u = par[u];
                path.push_back(u);
            }
            path.push_back(path[0]);
            reverse(path.begin(), path.end());
            cout<<path.size()<<"\n";
            for(ll p : path) {
                cout<<p + 1<<" ";
            }

            exit(0);
        }
        else {
            if(visi[v] == 0) {
                par[v] = u;
                dfs(v);
            }
        }
    }

    visi[u] = 2;
}

int main() {

    ll n, m; cin>>n>>m;
    par = vector<ll>(n, -1);
    visi = vector<ll>(n, 0);
    for(int edge = 0; edge < m; ++edge) {
        ll u, v;
        cin>>u>>v;
        --u, --v;
        graph[u].push_back(v);
    }

    for(int node = 0; node < n; ++node) {
        if(visi[node] == 0) {
            dfs(node);
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}