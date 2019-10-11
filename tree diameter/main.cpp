#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// tree diameter is the length of two leaf nodes
// first we choose any node and make a DFS traversal from it to get the farthest node
// then  we a make a DFS from it to get the farthest node again
ll max_count = 0 ;
ll farthest_node ;
vector< vector<ll> > adjList ;
vector<bool> vis;
void getFarthestNode(ll node, ll counter){
    if(vis[node])
        return;
    vis[node]=true;
    counter++;
    for(ll i=0;i<adjList[node].size();i++){
        ll child = adjList[node].at(i);
        if(vis[child]) continue;
        if(counter>=max_count){
            max_count=counter;
            farthest_node=child;
        }
        getFarthestNode(child,counter);
    }
}
int main()
{
    ll n , m ;
    cin >> n >> m ;
    adjList = vector< vector<ll> >(n);
    vis = vector<bool>(n,false);
    for(ll i=0;i<m;i++){
        ll a , b ;
        cin >> a >> b ;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    getFarthestNode(0,0);
    vis = vector<bool>(n,false);
    getFarthestNode(farthest_node,0);
    cout << max_count << endl;
    return 0;
}
