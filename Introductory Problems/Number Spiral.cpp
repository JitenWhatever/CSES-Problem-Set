/*
Time limit: 1.00 s Memory limit: 512 MB
A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

Your task is to find out the number in row y and column x.

Input

The first input line contains an integer t: the number of tests.

After this, there are t lines, each containing integers y and x.

Output

For each test, print the number in row y and column x.

Constraints
1≤t≤105
1≤y,x≤109
Example

Input:
3
2 3
1 1
4 2

Output:
8
1
15
*/


#include<bits/stdc++.h>


#define ll long long

using namespace std;


ll myPow(ll x, ll n) {

    if(n < 0) {
        x = 1/x;
    }

    ll result = 1, power = x;

    while(n != 0) {
        if(n % 2 != 0) {
            result *= power;
        }

        n /= 2;

        power *= power;
    }

    return result;
}



ll getElement(ll r, ll c) {
    ll max_index = max(r, c);
    ll result = max_index * (max_index - 1) + 1 + myPow(-1, max_index)*(r - c);

    return result;
}


int main() {

    ll n, r, c; cin>>n;
    while(n--) {
        cin>>r>>c;

        cout<<getElement(r, c)<<"\n";
    }
    return 0;
}
