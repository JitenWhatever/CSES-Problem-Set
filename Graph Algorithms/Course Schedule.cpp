/*
Time limit: 1.00 s Memory limit: 512 MB
You have to complete n courses. There are m requirements of the form "course a has to be completed before course b". 
Your task is to find an order in which you can complete the courses.

Input

The first input line has two integers n and m: the number of courses and requirements. The courses are numbered 1,2,…,n.

After this, there are m lines describing the requirements. Each line has two integers a and b: course a has to be completed before course b.

Output

Print an order in which you can complete the courses. You can print any valid order that includes all the courses.

If there are no solutions, print "IMPOSSIBLE".

Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example

Input:
5 3
1 2
3 1
4 5

Output:
3 4 1 5 2
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;   cin>>n>>m;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
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

    vector<int> path;

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        path.push_back(node);
        --n;

        for(int nbr : graph[node]) {
            if(--inDegree[nbr] == 0) {
                Q.push(nbr);
            }
        }
    }
    
    if(n != 0) {
        cout<<"IMPOSSIBLE\n";
    }
    else {
        for(int p : path) {
            cout<<p + 1<<" ";
        }
    }
    return 0;
}


