/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.

Input

The first input line has two integers n and m: the height and width of the map.

Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.

Output

First print "YES", if there is a path, and "NO" otherwise.

If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/

#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
const int MAX = 1001;
int n, m;

char graph[MAX][MAX];

struct point {
    int r, c, d;
};

bool isSafe(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m || graph[r][c] == '#') {
        return false;
    }

    return true;
}

int main() {
    boost;

    int sr, sc, dr, dc;
    cin>>n>>m;
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; c++) {
            cin>>graph[r][c];
            if(graph[r][c] == 'A'){
                sr = r;
                sc = c;
            }
            if(graph[r][c] == 'B') {
                dr = r;
                dc = c;
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    graph[sr][sc] = '#';
    queue<point> Q;

    Q.push({sr, sc, 0});

    int row[4] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    while(!Q.empty()) {
        point p = Q.front();
        Q.pop();
        int r = p.r, c = p.c, d = p.d;
        dist[r][c] = d;

        if(r == dr && c == dc) {
            cout<<"YES\n";
            cout<<d<<"\n";
            string path;
            while(r != sr || c != sc) {
                if(r > 0 && dist[r - 1][c] == d - 1) {
                    path.push_back('D');
                    --r;
                }
                else if(r < n - 1 && dist[r + 1][c] == d - 1) {
                    path.push_back('U');
                    ++r;
                }
                else if(c > 0 && dist[r][c - 1] == d - 1) {
                    path.push_back('R');
                    --c;
                }
                else {
                    path.push_back('L');
                    ++c;
                }
                --d;
            }

            reverse(path.begin(), path.end());
            cout<<path<<"\n";
            return 0;
        }
        for(int k = 0; k < 4; ++k) {
            int i = r + row[k], j = c + col[k];
            if(isSafe(i, j)) {
                graph[i][j] = '#';
                Q.push({i, j, d + 1});
            }
        }
    }

    cout<<"NO\n";

    
    return 0;
}


