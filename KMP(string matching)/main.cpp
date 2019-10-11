#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> lps;
void construct_lps(string pattern){
    ll m  = pattern.size();
    lps = vector<ll>(m,0);
    ll j=0;
    ll i=1;
    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            lps[i]=j;
            i++;
        }else {
            if(j!=0){
                j=lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
vector<ll> KMP_SEARCH(string text , string pattern){
    construct_lps(pattern);
    vector<ll> index ;
    ll n=text.size();
    ll m=pattern.size();
    ll i,j;
    i=j=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }

        if(j==m){
            index.push_back(i-j);
            j=lps[j-1];
        }

        else if(i<n&&pattern[j]!=text[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    return index;
}
int main()
{
    string text = "AABAACAADAABAABA";
    string pattern= "AABA";
    vector<ll> res = KMP_SEARCH(text,pattern);
    for(ll i=0;i<pattern.size();i++){
        cout << lps.at(i) << endl;
    }
    for(ll i=0;i<res.size();i++){
        cout << res.at(i) << " " ;
    }
    return 0;
}
