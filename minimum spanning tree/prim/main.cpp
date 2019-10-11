#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define OO 1E18
using namespace std;
// spanning tree is subgraph from graph connect all vertices
// #Edges = #vertices - 1
// #possible spanning trees = (|E| C |V|-1) - #cycles
// we have two greedy algorithms to find spanning tree with minimum cost:
//        (1) prim
//        (2) kruskal
// generic_MST(G){
//        A = {}
//        while A doesn't form a spanning tree:
//           find an edge(u,v) that is safe for A
//           A = A + {u,v}
//        return As
// different between two algorithms --> how to find safe edge in each step
struct edge{
    ll a , b , w , index;
};
vector<ll> keys;
vector<ll> parent;
vector< vector<edge> > adjList ;
void MST_PRIM(ll root , ll n){
    keys = vector<ll>(n,OO);
    parent = vector<ll>(n);
    keys[root]=0;
    priority_queue < pair<ll,ll> ,vector<pair<ll,ll> > , greater <pair<ll,ll> > > q;
    vector<bool> found(n,true);
    q.push(make_pair(0,root));
    while(!q.empty()){
        ll u = q.top().second;
        q.pop();
        if(!found[u]) continue;
        found[u]=false;
        for(ll i=0;i<adjList[u].size();i++){
             ll v = adjList[u][i].b;
             ll w = adjList[u][i].w;
             if(found[v]&&w<keys[v]){
                keys[v]=w;
                parent[v]=u;
                q.push(make_pair(w,v));
             }
        }
    }
}
int main()
{
     ll n,m ;
    cin >> n >> m ;
    adjList = vector<vector<edge> >(n);
    map< pair<ll,ll> , ll > arr ;
    for(ll i=0;i<m;i++){
        ll a , b , c ;
        cin >> a >> b >> c ;
        a--;
        b--;
        edge t ;
        t.a=a;
        t.b=b;
        t.w=c;
        t.index=i;
        adjList[a].push_back(t);
        t.a=b;
        t.b=a;
        adjList[b].push_back(t);
        arr[make_pair(min(a,b),max(a,b))]=c;
    }
    MST_PRIM(0,n);
    ll res= 0 ;
    for(ll i=1;i<n;i++){
        res+=arr[make_pair(min(i,parent[i]),max(i,parent[i]))];
    }

    cout << res ;
    return 0;
}
