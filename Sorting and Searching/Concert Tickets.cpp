/*
Time limit: 1.00 s Memory limit: 512 MB
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, 
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1,h2,…,hn: the price of each ticket.

The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output

Print, for each customer, the price that they will pay for their ticket. 
After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.

Constraints
1≤n,m≤2⋅10^5
1≤hi,ti≤10^9
Example

Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1
*/

#include<bits/stdc++.h>


using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n, m, x; cin>>n>>m;
    set<array<int, 2>> v;
    for(int index = 0; index < n; ++index) {
        cin>>x;
        v.insert({x, index});
    }

    for(int index = 0; index < m; ++index) {
        cin>>n;
        auto itr = v.lower_bound({n + 1, 0});
        if(itr == v.begin()) {
            cout<<"-1\n";
        }
        else {
            --itr;
            cout<<(*itr)[0]<<"\n";
            v.erase(itr);
        }
    }
    return 0;
}

