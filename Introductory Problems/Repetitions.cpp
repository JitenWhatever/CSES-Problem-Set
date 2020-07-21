/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

Input

The only input line contains a string of n characters.

Output

Print one integer: the length of the longest repetition.

Constraints
1≤n≤106
Example

Input:
ATTCGGGA

Output:
3
*/

#include<bits/stdc++.h>


using namespace std;

int main() {
    string s; cin>>s;

    char ch = 'A';
    int len = 0;
    int res = 0;
    for(char c : s) {
        if(ch == c){
            ++len;
            res = max(res, len);
        }
        else {
            len = 1;
            ch = c;
        }
    }

    cout<<res;
    return 0;
}