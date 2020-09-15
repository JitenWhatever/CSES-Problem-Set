/*
Time limit: 1.00 s Memory limit: 512 MB
There are n pupils in Uolevi's class, and m friendships between them. 
Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.

Input

The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,…,n.

Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.

Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.

Output

Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/


#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

vector<vector<int>> graph;
vector<bool> visi;
vector<int> color;

void dfs(int u, int c) {
    
    visi[u] = true;
    color[u] = c;
    for(int v : graph[u]) {
        if(!visi[v]) {
            dfs(v, 1 - c);
        }
    }
}

int main() {
    boost;

    int n, m, a, b;
    cin>>n>>m;
    graph = vector<vector<int>>(n);
    for(int edge = 0; edge < m; ++edge) {
        cin>>a>>b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    color = vector<int>(n, -1);
    visi = vector<bool>(n, false);

   
    for(int node = 0; node < n; ++node) {
        if(!visi[node]) {
            dfs(node, 0) ;
        }
    }

    bool bipartite = true;

    for(int u = 0; u < n ; ++u) {
        for(int v : graph[u]) {
            if(color[u] == color[v]) {
                bipartite = false;
                break;
            }
        }
    }
    if(bipartite) {
        for(int c : color) {
           cout<<c + 1<<" ";
        }
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }

    return 0;
}