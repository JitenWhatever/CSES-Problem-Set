/*
Time limit: 1.00 s Memory limit: 512 MB
Your task is to divide the numbers 1,2,…,n into two sets of equal sum.

Input

The only input line contains an integer n.

Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.

Constraints
1≤n≤106
Example 1

Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6

Example 2

Input:
6

Output:
NO
*/

#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n, index = 1; cin>>n;
    
    ll sum = n * (n + 1) ;

    if(sum % 4 != 0) {
        cout<<"NO\n";
        return 0;
    }
    ll ssum = 0;
    sum /= 4;
    vector<int> s1, s2;

    if(sum % n == 0) {
        s1.push_back(n);
        // ++index;
        ssum += n;
    }

    while(sum != ssum) {
        if(sum % n == 0) {
            s1.push_back(n - index);
            s1.push_back(index);

            ssum += n;
        }
        else {
            s1.push_back(n - index + 1);
            s1.push_back(index);

            ssum += n + 1;
        }

        index++;
    }

    cout<<"YES\n";
    
    sort(s1.begin(), s1.end());
    cout<<s1.size()<<"\n";
    index = 0;
    
    for(int i = 1; i <= n; ++i) {
        if(index < s1.size() && s1[index] == i) {
            cout<<i<<" ";
            ++index;
        }
        else {
            s2.push_back(i);
        }
    }
    cout<<"\n"<<s2.size()<<"\n";
    for(int num : s2) {
        cout<<num<<" ";
    }

    cout<<"\n";

    return 0;
}