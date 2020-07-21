/*
Time limit: 1.00 s Memory limit: 512 MB
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. 
Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).
 
For example, the path
 
corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
 
You are given a description of a path which may also contain characters ? (any direction). 
Your task is to calculate the number of paths that match the description.
 
Input
 
The only input line has a 48-character string of characters ?, D, U, L and R.
 
Output
 
Print one integer: the total number of paths.
 
Example
 
Input:
??????R??????U??????????????????????????LD????D?
 
Output:
201
*/
 
#include<bits/stdc++.h>
 
#define ll long long 
 
using namespace std;
 
vector<vector<char>> grid;
vector<vector<bool>> visi;
ll result = 0;
string s;
 
bool isSafe(int r, int c) {
    return (r >= 0 && r < 7 && c >= 0 && c < 7 && !visi[r][c]);
}
 
void dfs(int r, int c, int steps = 0) {
    if(r == 6 && c == 0) {
        if(steps == 48) {
            ++result;
        }
        return ;
    }
 
    visi[r][c] = true;
    if(s[steps] == '?' || s[steps] == 'L') {
        if(c && !visi[r][c - 1]){
            if(!(!isSafe(r, c - 2) && isSafe(r + 1, c - 1) && isSafe(r - 1, c - 1))) {
                dfs(r, c - 1, steps + 1);
            }
        }
    }
    if(s[steps] == '?' || s[steps] == 'R') {
        if(c < 6 && !visi[r][c + 1]){
            if(!(!isSafe(r, c + 2) && isSafe(r + 1, c + 1) && isSafe(r - 1, c + 1))) {
                dfs(r, c + 1, steps + 1);
            }
        }
    }
    if(s[steps] == '?' || s[steps] == 'U') {
        if(r && !visi[r - 1][c]){
            if(!(!isSafe(r - 2, c) && isSafe(r - 1, c + 1) && isSafe(r - 1, c - 1))) {
                dfs(r - 1, c, steps + 1);
            }
        }
    }
    if(s[steps] == '?' || s[steps] == 'D') {
        if(r < 6 && !visi[r + 1][c]){
            if(!(!isSafe(r + 2, c) && isSafe(r + 1, c + 1) && isSafe(r + 1, c - 1))) {
            dfs(r + 1, c, steps + 1);
            }
        }
    }
    visi[r][c] = false;
 
}
 
int main(){
    visi = vector<vector<bool>>(7, vector<bool>(7));
 
    cin>>s;
    dfs(0, 0);
    
    cout<<result<<"\n";
    return 0;
}