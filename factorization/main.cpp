#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
    *every integer greater than one is prime or product of prime
    *a number is perfect number if is equal to sum of its proper divisors
    *it is unknown whether there are any odd perfect numbers
    *every even perfect number is pf the form 2^(k-1)*(2^k-1) where k and 2^k-1 are prime
*/

// O(sqrt(N))
vector<ll> generate_divisors(ll n){
    vector<ll> v ;
    ll i=1;
    for(ll i=1;i*i<n;i++){
        if(n%i==0){
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    if(i*i==n)
        v.push_back(i);
    return v ;
}

// O(sqrt(N))
vector<ll> factorization(ll n){
    vector<ll> v ;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        v.push_back(n); // n is prime
    }

    return v ;

}
// count number of divisors in range n
ll rangeFactorization(ll n){
    vector<ll> v(n+1,0);
    ll s = 0 ;
    for(ll i=1;i<=n;i++){
        for(ll k=i;k<=n;k+=i){
            v[k]++;
        }
    }
    for(ll i=1;i<=n;i++){
        s+=v[i];
    }
    return s ;
}
int main()
{
    vector<ll> res = factorization(1000);
    for(ll i=0;i<res.size();i++) cout << res.at(i) << " " ;
    return 0;
}
