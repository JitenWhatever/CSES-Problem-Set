/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a map of a building, and your task is to count the number of its rooms. 
The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input

The first input line has two integers n and m: the height and width of the map.

Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output

Print one integer: the number of rooms.

Constraints
1≤n,m≤1000
Example

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/


#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
const int MAX = 1001;
int n, m;

char graph[MAX][MAX];


int dfs(int r, int c) {
    if(r < 0 ||  r >= n || c < 0 || c >= m || graph[r][c] == '#') {
        return 0;
    }

    graph[r][c] = '#';

    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r + 1, c);
    dfs(r, c - 1);
    return 1;
}

int main(){
    cin>>n>>m;
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; c++) {
            cin>>graph[r][c];
        }
    }

    int rooms = 0;
     for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; c++) {
            if(graph[r][c] == '.') {
                rooms += dfs(r, c);
            }
        }
    }

    cout<<rooms<<"\n";
    return 0;
}