#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define MAX 1e7+7
using namespace std;
// sqrt(N)
 bool isPrime(ll n ){
    if(n==2) return true ;
    if(n<2||n%2==0) return false;

    for(ll i=3;i*i<n;i+=2){
            if(n%i==0) return false;
    }
    return true ;
}
vector<ll> primes ;
// O(n log n )
void sieveSundaram(ll n){
   // operation=0;
     ll nNew = (n-2)/2;
     bool marked[nNew+1];
     memset(marked,false,sizeof(marked));
     for(ll i=1;i<=nNew;i++){
        for(ll j=i;(i+j+2*i*j)<=nNew;j++){
            marked[i+j+2*i*j]=true;
           // operation++;
        }
     }
     if(n>2){
        primes.push_back(2);
     }

     for(ll i=1;i<=nNew;i++){
        if(marked[i]==false){
            primes.push_back(2*i+1);
           // operation++;
        }
     }
}
ll getPower(ll num, ll base)
{
    ll res = 0 ;
    while(num%base==0)
    {
        num/=base;
        res++;
    }
    return res ;
}
set<ll> primeFactors;
void prime_factors(ll n )
{
       while(n%2==0){
         primeFactors.insert(2);
         n=n/2;
       }

       for(ll i=3;i*i<=n;i+=2){
          while(n%i==0){
              primeFactors.insert(i);
              n=n/i;
          }
       }

       if(n>2)
          primeFactors.insert(n);
}
// every even integer greater than two can represent as sum of two prime numbers
void goldbach(ll n){
     if(n<=2 || n%2!=0){
        return;
     }
     for(ll i=0;primes[i]<=n/2;i++){
         ll diff = n - primes[i] ;
         if(binary_search(primes.begin(),primes.end(),diff)){
              cout << primes[i] << " " << diff << endl;
              return ;
         }
     }
}
int main()
{
      sieveSundaram(MAX);
}
