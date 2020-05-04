#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;



/*
    fin(n) = fib(n-1)+fib(n-2)
    fib(0)=fib(1)=1
    memoization: recursive function and save calls

*/

// order 2^n
ll fib(ll n ){

  if(n<=1) return 1 ;

  return fib(n-1)+fib(n-2);
}

// order n
ll DP[1000000]; // to save answers
ll fib_memo(ll n ){
    if(n<=1){
        return 1 ;
    }

    if (DP[n]!=0 ){
        return DP[n];
    }

    return DP[n] = fib_memo(n-2)+fib_memo(n-1);
}

ll fib_DP(ll n){

   ll fibb[100000];
   fibb[0]=fibb[1]=1;
   for( ll i=2;i<=n;i++){
      fibb[i]=fibb[i-1]+fibb[i-2];
   }
   return fibb[n] ;
}
int main()
{
   cout << fib(5) << endl ;
   cout << fib_memo(500) << endl ;
   cout << fib_DP(500) << endl ;
    return 0;
}
