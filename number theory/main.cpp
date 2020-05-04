#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// O(log[min(a,b)])
ll gcd(ll a , ll b){
   if(b==0)
      return a ;
   return gcd(b,a%b);
}
ll lcm(ll a,ll b){
   return (a*b)/gcd(a,b);
}
// O(log[p] base 2)
ll fastPow(ll b,ll p){
 if(p==0) return 1;
 ll sq = fastPow(b,p/2);
 sq*=sq;
 if(p%2==1)
     sq*=b;
 return sq ;
}
ll fastPowMod(ll b , ll p , ll mod){
  b%=mod;
  if(b==0)
     return 0 ;
  if(p==0)
    return 1 ;
  ll st = fastPowMod(b,p/2,mod);
  st = ((st%mod)*(st%mod))%mod;

  if(p%2==1)
    st=((st%mod)*(b%mod))%mod;

  return st%mod ;
}
// calculate(a^1+a^2+.....+a^k)
// O(k)
ll sumPows(ll a , ll k ){
   if(k==0)
      return 0 ;

   if(k%2==1){
      return a*(1+sumPows(a,k-1));
   }

   ll half = sumPows(a,k/2);
   return half*(1+half-sumPows(a,k/2-1));
}


int main()
{
    cout << gcd(1000000,1500000) << endl;
    cout << lcm(5,9) << endl ;
    cout << fastPow(5,15) ;
    return 0;
}
