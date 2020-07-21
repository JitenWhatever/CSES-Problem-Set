/*
Time limit: 1.00 s Memory limit: 512 MB

A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.

Given n, construct a beautiful permutation if such a permutation exists.

Input

The only input line contains an integer n.

Output

Print a beautiful permutation of integers 1,2,…,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".

Constraints
1≤n≤106
Example 1

Input:
5

Output:
4 2 5 3 1

Example 2

Input:
3

Output:
NO SOLUTION
*/


#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n; cin>>n;
    
    if(n == 1) {
        cout<<1;
        return 0;
    }
    else if(n <= 3) {
        cout<<"NO SOLUTION";
        return 0;
    }
   
   if(n == 4) {
       cout<<2<<" "<<4<<" "<<1<<" "<<3;
       return 0;
   }

   if(n%2 == 0) {

       for(int index = n ; index >= 2; index -= 2){
           cout<<index<<" ";
       }
       for(int index = n - 1; index >= 1; index -= 2) {
           cout<<index<<" ";
       }
   }
   else {
       for(int index = n - 1; index >= 2; index -= 2) {
           cout<<index<<" ";
       }
       for(int index = n ; index >= 1; index -= 2){
           cout<<index<<" ";
       }
   }

    return 0;
}

