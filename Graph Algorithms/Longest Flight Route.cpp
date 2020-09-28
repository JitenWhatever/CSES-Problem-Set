/*
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.

Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.

Output

First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
5 5
1 2
2 5
1 3
3 4
4 5

Output:
4
1 3 4 5
*/

#include<bits/stdc++.h>

using namespace std;

const int INF=1e9;

int main(){
    int n, m;   cin>>n>>m;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);
    for(int edge = 0; edge < m; ++edge) {
        int a, b; cin>>a>>b;
        --a;
        --b;
        graph[a].push_back(b);
        ++inDegree[b];
    }

    queue<int> Q;
    for(int node = 0; node < n; ++node) {
        if(inDegree[node] == 0) {
            Q.push(node);
        }
    }

    int cycle = n;
    vector<int> path;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        path.push_back(node);
        --cycle;

        for(int nbr : graph[node]) {
            if(--inDegree[nbr] == 0) {
                Q.push(nbr);
            }
        }
    }

    if(cycle != 0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    vector<int> dist(n, -INF);
    dist[0] = 0;
    vector<int> par(n, -1);
    for(int node : path) {
        for(int nbr : graph[node]) {
            if(dist[nbr] < dist[node] + 1) {
                dist[nbr] = dist[node] + 1;
                par[nbr] = node;
            }
        }
    }

    if(dist[n - 1] < 0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    path.clear();
    int node = n - 1;
    path.push_back(node);
    while(node != 0) {
        node = par[node];
        path.push_back(node);
    }

    reverse(path.begin(), path.end());

    cout<<path.size()<<"\n";
    for(int p: path) {
        cout<<p + 1<<" ";
    }
   
    return 0;
}