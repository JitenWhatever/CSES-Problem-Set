/*
Time limit: 1.00 s Memory limit: 512 MB
A Gray code is a list of all 2n bit strings of length n, 
where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

Your task is to create a Gray code for a given length n.

Input

The only input line has an integer n.

Output

Print 2n lines that describe the Gray code. You can print any valid solution.

Constraints
1≤n≤16
Example

Input:
2

Output:
00
01
11
10
*/

#include<bits/stdc++.h>

using namespace std;

int main() {

    int n; cin>>n;
    for (int num = 0; num < 1<<n; ++num) {
        int code = num ^ (num >> 1);
        bitset<32> s(code);

        string gc = s.to_string();

        cout<<gc.substr(32 - n)<<"\n";
    }
    return 0;
}