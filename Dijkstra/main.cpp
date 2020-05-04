#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define OO (ll)1e18+1
using namespace std;
/*
 * find shorted path from single source to any node in the graph
 * by intuition it never have cycle
 * steps:
        1-pick non visited node with minimum cost
        2-relax graph using this node (remove this node and its info distributed on graph)
 * we can represent the graph using:
        1- adj matrix --> O(N*N)
        2- adj list --> O(N log(N))  using queue
*/
ll dijkstra1(vector< vector<ll> > adjMat,ll src , ll dest , vector<ll> prev){
    ll n = adjMat.size(); // number of nodes
    vector<ll> dist(n,OO); // initialize distance between source and any node infinity
    prev=vector<ll>(n);
    vector<bool> vis(n,false);
    dist[src]=0;
    while(true){
        ll val = OO , idx=-1;
        // pick non visited node with minimum cost
        rep(i,n){
                if(vis[i]&&dist[i]<val){
                    val = dist[i];
                    idx=i;
                }
        }
        // visit all nodes or the shorted path is the dist between source and destination
        if(idx==-1||idx==dest){
            break;
        }
        //this node will be  deleted
        vis[idx]=true;
        //  relax graph using this node
        rep(i,n){
            if(adjMat[idx][i]!=OO&&dist[i]>(val=dist[idx]+adjMat[idx][i])){
                dist[i]=val;
                prev[i]=idx;
            }
        }
    }
    ll res = dist[dest];
    // return -1 means that there no path between source and destination
    return  res==OO?-1:res;
}
int main()
{

    return 0;
}
