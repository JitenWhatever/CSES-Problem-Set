/*
Time limit: 1.00 s Memory limit: 512 MB
The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

Your task is to calculate the edit distance between two strings.

Input

The first input line has a string that contains n characters between A–Z.

The second input line has a string that contains m characters between A–Z.

Output

Print one integer: the edit distance between the strings.

Constraints
1≤n,m≤5000
Example

Input:
LOVE
MOVIE

Output:
2
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    string A, B;
    cin>>A>>B;
    int dp[A.length() + 1][B.length() + 1];

    for(int r = 0; r <= (int)A.length(); ++r) {
        for(int c = 0; c <= (int)B.length(); ++c) {
            if(r == 0 && c == 0) {
                dp[r][c] = 0;
                continue;
            }

            if(r == 0) {
                dp[r][c] = dp[r][c - 1] + 1;
                continue;
            }

            if(c == 0) {
                dp[r][c] = dp[r - 1] [c] + 1;
                continue;
            }
        
            if(A[r - 1] == B[c - 1]) {
                dp[r][c] = dp[r - 1][c - 1];
            }
            else {
                dp[r][c] = min({dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]})  + 1;
            }
        }
    }

    cout<<dp[A.length()][B.length()]<<"\n";
    return 0;
}