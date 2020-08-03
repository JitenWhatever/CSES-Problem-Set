/*
Time limit: 1.00 s Memory limit: 512 MB
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.

What is the longest sequence of successive songs where each song is unique?

Input

The first input line contains an integer n: the number of songs.

The next line has n integers k1,k2,…,kn: the id number of each song.

Output

Print the length of the longest sequence of unique songs.

Constraints
1≤n≤2⋅10^5
1≤ki≤10^9
Example

Input:
8
1 2 1 3 2 7 4 2

Output:
5
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n; cin>>n;
    vector<int> v(n);
    for(int index = 0; index < n; ++index) {
        cin>>v[index];
    }

    set<int> st;
    int window = 0, left = 0, right = 0;
    while(right < n) {
        if(st.count(v[right]) == 0) {
            st.insert(v[right++]);
            window = max(window, (int)st.size());
        }
        else if(left < n){
            st.erase(v[left++]);
        }
    }

    cout<<window<<"\n";
    return 0;
}

