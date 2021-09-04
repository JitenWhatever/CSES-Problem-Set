/*
Consider an infinite string that consists of all positive integers in increasing order:

12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?

Input

The first input line has an integer q: the number of queries.

After this, there are q lines that describe the queries. Each line has an integer k: a 1-indexed position in the string.

Output

For each query, print the corresponding digit.

Constraints
1≤q≤1000
1≤k≤10^18
Example

Input:
3
7
19
12

Output:
7
4
1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll pow(ll x, unsigned ll y){
    ll res=1;
    while(y>0){
        if (y&1) {
            res= (res*x); 
            y=y>>1; 
            x=(x*x);
        }
    }
    return res;
}

int main(){
    ll q; cin>>q;
    vector<ll> powerOfTen(19, 1); // limit is 10^18 // powers[i] => 10 power i
    for (int power = 1; power <= 18; ++power) {
        powerOfTen[power] = powerOfTen[power - 1] * 10;
    }
    while(q--) {
        ll index; cin>>index;
        ll digitsSoFar = 0, digitsBeforeActualBlock = 0;
        int numberOfDigits;
        for (int digits = 1; digits <= 18; ++digits) {
            digitsSoFar += (powerOfTen[digits] - powerOfTen[digits - 1]) * digits;
            if (digitsSoFar >= index) {
                numberOfDigits = digits;
                break;
            }
            digitsBeforeActualBlock += (powerOfTen[digits] - powerOfTen[digits - 1]) * digits;
        }

        ll low = powerOfTen[numberOfDigits - 1];
        ll high = powerOfTen[numberOfDigits] - 1;
        ll bestValue = 0;
        ll startingPositionOfBestValue;
        while (low <= high) {
           ll actualValue = (low + high)/2; 
           ll startingPositionOfActualValue = digitsBeforeActualBlock + 1 + (actualValue - powerOfTen[numberOfDigits - 1])*numberOfDigits;

           if (startingPositionOfActualValue <= index) {
               if (actualValue > bestValue) {
                   bestValue = actualValue;
                   startingPositionOfBestValue = startingPositionOfActualValue;
               }

               low = actualValue + 1;
           } else {
               high = actualValue - 1;
           }
        }
        string number = to_string(bestValue);
        cout<<number[index - startingPositionOfBestValue]<<"\n";
    }
}
