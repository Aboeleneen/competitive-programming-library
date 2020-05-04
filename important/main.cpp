#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// get sum of all sub array
// every element appear in beginning of (n-i) sub array
// every element appear in the middle of (n-i)*i sub array
// total of appearance = (n-i)*(i+1)
ll sum_subarray(vector<ll> arr){
    ll res = 0 ;
    for(ll i=0;i<arr.size();i++){
        res+=(arr[i]*(arr.size()-i)*(i+1));
    }
    return res;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
