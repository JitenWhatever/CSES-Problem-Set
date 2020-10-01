/*
Time limit: 1.00 s Memory limit: 512 MB
A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. 
The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

Input

The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,…,n.

After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output

Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
4 5
1 2
2 4
1 3
3 4
1 4

Output:
3
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visi;

int n, m;

const int MOD=1e9 + 7;

vector<int> dp;

int dfs(int u) {
    if(u == n - 1) {
        dp[u] = 1;
        visi[u] = 2;
        return 0;
    }
    visi[u] = 1;

    for(int v : graph[u]) {
        if(visi[v] == 0) {
            dfs(v);
        }
        dp[u] = (dp[u]%MOD + dp[v]%MOD)%MOD;
    }

    visi[u] = 2;

    return dp[u];
}

int main() {
    cin>>n>>m;
    graph = vector<vector<int>>(n);
    visi = vector<int>(n);
    dp = vector<int>(n);
    for(int edge = 0; edge < m; ++edge) {
        int a, b;
        cin>>a>>b;
        --a;
        --b;
        graph[a].push_back(b);
    }

    dfs(0);
    cout<<dp[0]<<"\n";
    return 0;
}