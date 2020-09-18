/*
Time limit: 1.00 s Memory limit: 512 MB
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneoulsy take one as well. 
Your goal is to reach one of the boundary squares without ever sharing a square with a monster.

Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input

The first input line has two integers n and m: the height and width of the map.

After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

Output

First print "YES" if your goal is possible, and "NO" otherwise.

If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R. You can print any path, as long as its length is at most n⋅m steps.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

const int MAX = 10001;
char grid[MAX][MAX];
bool visi[MAX][MAX];
int dist[MAX][MAX];
map<pair<int, int>, pair<int, int>> parent;
vector<pair<int, int>> monsters;
pair<int, int> src, dst;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, 1, -1};
int n, m;

bool isSafe(int r, int c, int d) {
    if(r < 0 || r >= n || c < 0 || c >= m || dist[r][c] <= d) {
        return false;
    }

    return true;
}

bool isGoal(int r, int c, int d) {
    
    if(!isSafe(r, c, d)) {
        return false;
    }
    if(r == 0 || r == n - 1 || c == 0 || c == m - 1) {
        return true;
    }
    return false;
}


void bfs_monsters() {
    queue<pair<int, pair<int, int>>> Q;

    for(pair<int, int> monster : monsters) {
        Q.push({0, {monster.first, monster.second}});
    }

    while(!Q.empty()) {
        int d = Q.front().first;
        int r = Q.front().second.first;
        int c = Q.front().second.second;
        Q.pop();
        ++d;

        for(int dir = 0; dir < 4; ++dir) {
            int i = r + row[dir];
            int j = c + col[dir];
            if(isSafe(i, j, d)){
                dist[i][j] = d;
                Q.push({d, {i, j}});
            }
        }
    }
}

bool bfs_src() {
    queue<pair<int, pair<int, int>>> Q;

    Q.push({0, src});
    parent[src] = {-1, -1};

    while(!Q.empty()) {
        int d = Q.front().first;
        int r = Q.front().second.first;
        int c = Q.front().second.second;
        ++d;
        Q.pop();

        for(int dir = 0; dir < 4; ++dir) {
            int i = r + row[dir];
            int j = c + col[dir];
            
            if(isGoal(i, j, d)) {
                parent[{i, j}] = {r, c};
                dst = {i, j};
                return true;
            }
            else if(isSafe(i, j, d)) {
                parent[{i, j}] = {r, c};
                dist[i][j] = d;
                Q.push({d, {i, j}});
            }
        }
    }

    return false;
}


int main() {
    fastio;
    cin>>n>>m;
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < m; ++c) {
            cin>>grid[r][c];

            if(grid[r][c] == 'A') {
                src = {r, c};
                dist[r][c] = 0;
            }
            else if(grid[r][c] == 'M') {
                dist[r][c] = 0;
                monsters.push_back({r, c});
            }
            else if(grid[r][c] == '#') {
                dist[r][c] = 0;
            }
            else {
                dist[r][c] = INT_MAX;
            }
        }
    }
    
    if(src.first == 0 || src.first == n - 1 || src.second == 0 || src.second == m - 1) {
        cout<<"YES\n0\n";
        return 0;
    }

    bfs_monsters();


    if(bfs_src()) {
        cout<<"YES\n";
        vector<char> path;
        pair<int,int> par = parent[dst];
        src = {-1, -1};
        while(par != src) {
            if(dst.second - par.second == 1 && dst.first - par.first == 0) {
                path.push_back('R');
            }
            if(dst.second - par.second == -1 && dst.first - par.first == 0) {
                path.push_back('L');
            }
            if(dst.second - par.second == 0 && dst.first - par.first == 1) {
                path.push_back('D');
            }
            if(dst.second - par.second == 0 && dst.first - par.first == -1) {
                path.push_back('U');
            }

            dst = parent[dst];
            par = parent[dst];
        }

        reverse(path.begin(), path.end());
        cout<<path.size()<<"\n";
        for(char ch : path) {
            cout<<ch;
        }
    }
    else{
        cout<<"NO\n";
    }

    // for(int r = 0; r < n ;++r) {
    //     for(int c = 0; c < m; ++c) {
    //         cout<<dist[r][c]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}