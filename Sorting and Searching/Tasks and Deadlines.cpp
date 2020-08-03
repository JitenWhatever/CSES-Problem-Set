/*
Time limit: 1.00 s Memory limit: 512 MB
You have to process n tasks. Each task has a duration and a deadline, 
and you will process the tasks in some order one after another. 
Your reward for a task is d−f where d is its deadline and f is your finishing time. 
(The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)

What is your maximum reward if you act optimally?

Input

The first input line has an integer n: the number of tasks.

After this, there are n lines that describe the tasks. 
Each line has two integers a and d: the duration and deadline of the task.

Output

Print one integer: the maximum reward.

Constraints
1≤n≤2⋅10^5
1≤a,d≤10^6
Example

Input:
3
6 10
8 15
5 12

Output:
2
*/


#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define boost std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
 
int main(){
    boost;
    ll n; cin>>n;
    array<int, 2> t[n];
    
    for(int index = 0; index < n; ++index) {
        cin>>t[index][0]>>t[index][1];
    }

    sort(t, t + n);
    
    ll reward = 0, time = 0;
    for(array<int, 2> num : t) {
        time += num[0];
        reward += (num[1] - time);
    }

    cout<<reward<<"\n";
    return 0;
}