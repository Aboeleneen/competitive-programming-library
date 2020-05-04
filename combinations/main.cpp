#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
     (1) nCr = n! / [r! * (n-r)! ]

*/
ll fact(ll n){
    ll res = 1 ;
   for(ll i=1;i<=n;i++){
      res*=i ;
   }
   return res ;
}

ll nCr ( ll n , ll r){
   return fact(n)/(fact(r)*fact(n-r)) ;
}
int main()
{

    return 0;
}
