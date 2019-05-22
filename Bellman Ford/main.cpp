#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define OO 1e9+7
using namespace std;
struct edge{
    ll weight , start , finish ;
};
vector<ll> dist;
vector<edge> edges;
bool bellmanFord(ll src, ll n){
    dist = vector<ll>(n,OO);
    dist[src]=0;
    for(ll i=0;i<n-1;i++){
        bool noChange = true;
        for(ll j=0;j<edges.size();j++){
            // relaxation step
            if(dist[edges[j].start]+edges[j].weight<dist[edges[j].finish]){
                dist[edges[j].finish] = dist[edges[j].start]+edges[j].weight;
                noChange=false;
            }
        }
        if(noChange) return true;
    }
    // check if there is negative cycle
     bool noChange = true ;
      for(ll j=0;j<edges.size();j++){
            // relaxation step
            if(dist[edges[j].start]+edges[j].weight<dist[edges[j].finish]){
                dist[edges[j].finish] = dist[edges[j].start]+edges[j].weight;
                noChange=false;
            }
    }
    return noChange;

}
int main()
{
    ll n , m ;
    cin >> n >> m;
    edges = vector<edge>(m);
    for(ll i=0;i<m;i++){
        ll a , b ,c ;
        cin >> a >> b >> c ;
        a--;
        b--;
        edge t;
        t.start=a;
        t.finish=b;
        t.weight=c;
        edges.push_back(t);
    }
    cout << bellmanFord(0,n);
    for(ll i=0;i<n;i++){
        cout << i+1 << " --> " << dist[i] << endl;
    }

    return 0;
}
