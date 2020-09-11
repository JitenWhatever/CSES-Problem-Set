/*
Time limit: 1.00 s Memory limit: 512 MB
There are n projects you can attend. For each project, 
you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.

What is the maximum amount of money you can earn?

Input

The first input line contains an integer n: the number of projects.

After this, there are n lines. Each such line has three integers ai, bi, and pi: the starting day, the ending day, and the reward.

Output

Print one integer: the maximum amount of money you can earn.

Constraints
1≤n≤2⋅10^5
1≤ai≤bi≤10^9
1≤pi≤10^9
Example

Input:
4
2 4 4
3 6 6
6 8 2
5 7 3

Output:
7
*/

#include <bits/stdc++.h>
using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define ll  long long


struct project {
    ll s, e, r;
};

vector<ll> points;
int getNext(ll num) {
    auto itr = lower_bound(points.begin(), points.end(), num);
    if(itr == points.begin()) {
        return 0;
    }
    --itr;
    return 1 + distance(points.begin(), itr) ;
}

int main() {
    boost;
    ll n; cin>>n;
    
    vector<project> p(n + 1);
    
    for(int index = 1; index <= n; ++index) {
       
        cin>>p[index].s>>p[index].e>>p[index].r;
    }

    sort(p.begin() + 1, p.end(), [](project& a, project& b){
        return a.e < b.e;
    });

    for(int index = 1; index <= n; ++index) {
        points.push_back(p[index].e);
    }

    
    vector<ll> dp(n + 1);

    dp[0] = 0;

    for(int index = 1; index <= n; ++index) {

        ll ans1 = dp[index - 1];
      
        int next = getNext(p[index].s);

        ll ans2  = dp[next] + p[index].r;
        

        dp[index] =  max(ans1, ans2);
    }   

    cout<<dp[n]<<endl;
}