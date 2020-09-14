/*
Time limit: 1.00 s Memory limit: 512 MB
Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.

Input

The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,…,n. Uolevi's computer is 1 and Maija's computer is n.

Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.

Every connection is between two different computers, and there is at most one connection between any two computers.

Output

If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.

If there are no routes, print "IMPOSSIBLE".

Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/

#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
const int MAX = 1001;
int n, m;

int main() {
    int n, m, a, b;
    cin>>n>>m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visi(n + 1, false);
    vector<int> parent(n + 1, -1);
    for(int edge = 0; edge < m; ++edge) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);

    visi[1] =  true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(u == n) {
            vector<int> result;
            result.push_back(u);
            while(u != 1) {
                u = parent[u];
                result.push_back(u);
            }

            reverse(result.begin(), result.end());
            cout<<result.size()<<"\n";
            for(int num : result) {
                cout<<num<<" ";
            }
            return 0;
        }

        for(int v : graph[u]) {
            if(!visi[v]) {
                parent[v] = u;
                Q.push(v);
                visi[v] = true;
            }
        }

    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}