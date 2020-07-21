/*
Time limit: 1.00 s Memory limit: 512 MB
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

Input

The only input line has a string of length n consisting of characters A–Z.

Output

Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example

Input:
AAAACACBA

Output:
AACABACAA
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;   cin>>s;

    vector<int> hash(26, 0);
    int odd = 0;
    for(char ch : s) {
        hash[ch - 'A']++;
    }

    int oddIndex = 0;
    bool found = false;
    for(int index = 0; index < 26; ++index) {
        if(hash[index] & 1) {
            odd++;
            found = true;
            oddIndex = index;
        }
        if(odd > 1) {
            cout<<"NO SOLUTION\n";
            return 0;
        }

    }

    string result ;

    for(int index = 0; index < 26; ++index) {
        if(hash[index] != 0 && (hash[index]&1)^1) {
            for(int itr = 0; itr < hash[index]/2; ++itr) {
                result += (char)('A' + index);
            }
        }
    }

    string oddString ;
    if(found) {
        for(int itr = 0; itr < hash[oddIndex]; ++itr) {
            oddString += (char)('A' + oddIndex);
        }
    }

    string rev = result;
    reverse(rev.begin(), rev.end());
    result = result + oddString + rev;

   cout<<result<<"\n";


    return 0;
}