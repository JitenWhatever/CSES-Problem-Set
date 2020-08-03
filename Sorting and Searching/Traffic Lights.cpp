/*
Time limit: 1.00 s Memory limit: 512 MB
There is a street of length x whose positions are numbered 0,1,…,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

Your task is to calculate the length of the longest passage without traffic lights after each addition.

Input

The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.

Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights. Each position is distinct.

Output

Print the length of the longest passage without traffic lights after each addition.

Constraints
1≤x≤10^9
1≤n≤2⋅10^5
0<pi<x
Example

Input:
8 3
3 6 2

Output:
5 3 3
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int x, n ; cin>>x>>n;
    set<int> st;
    multiset <int> mst;
    st.insert(0);
    st.insert(x);
    vector<int> p(n);
    for(int index = 0; index < n; index++) {
        cin>>p[index];
        auto l = st.lower_bound(p[index]), r = st.upper_bound(p[index]);

        if(*l > p[index]) {
            --l;
        }
        if(*r < p[index]) {
            ++r;
        }

        auto res = mst.find(*r - *l);

        if(res != mst.end()) {
            mst.erase(res);
        }

        mst.insert(p[index] - *l);
        mst.insert(*r - p[index]);
        st.insert(p[index]);
        cout << *--mst.end() << ' ';
    }
    return 0;
}