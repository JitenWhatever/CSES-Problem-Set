/*
Time limit: 1.00 s Memory limit: 512 MB
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, 
and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

Every road is between two different cities, and there is at most one road between any two cities.

Output

First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3
*/

#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

vector<vector<int>> graph;
vector<bool> visi;
vector<int> par;

int s, e;

bool dfs(int node, int parent) {
    
    visi[node] = true;
    par[node] = parent;
    
    for(int next : graph[node]) {

        if(next == parent) { // self loop
            continue;
        }
        if(visi[next]) {   
            s = next;
            e = node;
            return true;
        }
        else {
            if(dfs(next, node)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    boost;
    int n, m, a, b; 
    cin>>n>>m;
   
    graph = vector<vector<int>>(n + 1);
    visi = vector<bool>(n + 1, false);
    par = vector<int>(n + 1, -1);
  
    for(int index = 0; index < m; ++index) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bool cycle = false;
    for(int node = 1; node <= n; ++node) {
        if(!visi[node]) {
            if(dfs(node, -1)) {
                cycle = true;
                break;
            }
        }
    }

    vector<int> path;
    if(cycle) {
        path.push_back(e);
        while(e != s) {
            e = par[e];
            path.push_back(e);
        }
        path.push_back(path[0]);

        cout<<path.size()<<"\n";
        for(int num : path) {
            cout<<num<<" ";
        }
    } 
    else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}