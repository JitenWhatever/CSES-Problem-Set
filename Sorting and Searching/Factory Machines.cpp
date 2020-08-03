/*
Time limit: 1.00 s Memory limit: 512 MB
A factory has n machines which can be used to make products. Your goal is to make a total of t products.

For each machine, you know the number of seconds it needs to make a single product. 
The machines can work simultaneously, and you can freely decide their schedule.

What is the shortest time needed to make t products?

Input

The first input line has two integers n and t: the number of machines and products.

The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.

Output

Print one integer: the minimum time needed to make t products.

Constraints
1≤n≤2⋅10^5
1≤t≤10^9
1≤ki≤10^9
Example

Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n, t; cin>>n>>t;
    ll  low = 0, high = 1e18;
    vector<ll> v(n);
    for(int index = 0; index < n; ++index) {
        cin>>v[index];
    }

    while(low < high) {
        ll mid = low + (high - low)/2, sum = 0;
        for(int num : v) {
            sum += min(mid/num, (ll)1e9);
        }

        if(sum >= t) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout<<low<<"\n";
    return 0;
}
