#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll> > adjlist , comps ;
vector<ll> inStack , dfs , lowlink , comp ;
stack<ll> stk ;
ll num = 0 ;
void targan(ll node){
    lowlink[node]=dfs[node]=num++;
    inStack[node]=1;
    stk.push(node);
    for(ll i=0;i<adjlist[node].size();i++){
        ll child = adjlist[node][i];
        if(dfs[child]==-1){
            targan(child);
            lowlink[node]=min(lowlink[node],lowlink[child]);
        }
        else if (inStack[node]=1){
            lowlink[node]=min(lowlink[node],dfs[child]);
        }
    }

    if(lowlink[node]=dfs[node]){
        vector<ll> component ;
        ll x = -1 ;
        while(x!=node){
            x=stk.top();
            stk.pop();
            inStack[x]=-1;
            component.push_back(x);
            comp[x]=comps.size()-1;
        }
        comps.push_back(component);
    }
}
int main()
{

    return 0;
}
