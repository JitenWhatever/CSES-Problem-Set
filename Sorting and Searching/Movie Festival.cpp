/*
Time limit: 1.00 s Memory limit: 512 MB
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

Input

The first input line has an integer n: the number of movies.

After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9
Example

Input:
3
3 5
4 9
5 8

Output:
2
*/

#include<bits/stdc++.h>

using namespace std;

#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    int n; cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int index = 0; index < n; ++index) {
        cin>>v[index][1]>>v[index][0];
    }

    sort(v.begin(), v.end());
    int last  = 0, result = 0;

    for(int index = 0; index < n; index++) {
        if(v[index][1] >= last) {
            ++result;

            last = v[index][0];
        }
    }

    cout<<result<<"\n";
    return 0;
}
