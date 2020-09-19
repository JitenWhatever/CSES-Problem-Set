/*
Time limit: 1.00 s Memory limit: 512 MB
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

Input

The first input line has three integers n, m and q: the number of cities, roads, and queries.

Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.

Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output

Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1≤n≤500
1≤m≤n2
1≤q≤10^5
1≤a,b≤n
1≤c≤10^9
Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define l long long
#define MAX 1e17

int main() {
    fastio;
    int n, m, q, u, v, w;

    cin>>n>>m>>q;
    l dist[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = MAX;
            }
        }
    }
    
    for(int edge = 0; edge < m; ++edge) {
        cin>>u>>v>>w;
        --u;
        --v;
        if(dist[u][v] > w) {
            dist[u][v] = dist[v][u] = w;
        }
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    while(q--) {
        cin>>u>>v;
        l value = dist[--u][--v];
        if(value == MAX) {
            cout<<"-1\n";
        }
        else {
            cout<<value<<"\n";
        }  
    }
    return 0;
}