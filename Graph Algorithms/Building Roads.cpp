/*
Time limit: 1.00 s Memory limit: 512 MB
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

A road always connects two different cities, and there is at most one road between any two cities.

Output

First print an integer k: the number of required roads.

Then, print k lines that describe the new roads. You can print any valid solution.

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
4 2
1 2
3 4

Output:
1
2 3
*/


#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
const int MAX = 1001;
int n, m;
vector<vector<int>> graph;
vector<bool> visi;
// char graph[MAX][MAX];

void dfs(int u) {
    if(visi[u]) {
        return ;
    }

    visi[u] = true;

    // cout<<u<<endl;
    for(int v : graph[u]) {
        dfs(v);
    }
}

int main() {
    boost;
    int n, m, a, b; 
    cin>>n>>m;
    visi = vector<bool>(n, false);
    graph =  vector<vector<int>>(n);;
    for(int edge = 0; edge < m; ++edge) {
        cin>>a>>b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> result;
    for(int u = 0; u < n; ++u) {
        if(!visi[u]) {
            result.push_back(u + 1);
            dfs(u);
        }
    }   

    cout<<result.size() - 1<<"\n";
    for(int index = 1; index < (int)result.size(); ++index) {
        cout<<result[index - 1]<<" "<<result[index]<<"\n";
    }
    return 0;
}