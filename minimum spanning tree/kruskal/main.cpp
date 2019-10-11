#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> parent , Rank ;
// make every node as a set
void initialize(int n){
    parent = vector<ll>(n);
    Rank = vector<ll>(n);
    for(ll i=0;i<n;i++){
        parent[i]=i;
        Rank[i]=i;
    }
}
// find parent and path compression
int find_set(int n){
    if(n == parent[n]){
        return n;
    }
    return parent[n]=find_set(parent[n]);
}
// union by rank
void link(int x , int y){
    if(Rank[x]>Rank[y]) swap(x,y);
    parent[x]=y;
    if(Rank[x]==Rank[y]) Rank[y]++;
}
// union of two different sets
void Union(int x , int y){
    int parentX = find_set(x);
    int parentY = find_set(y);
    if(parentX==parentY) return;
    link(parentX,parentY);
    parent[parentX]=parentY;
}

struct edge{
    ll from  , to , weight;
    edge(int from , int to , int weight):from(from) , to(to) ,weight(weight){}

    bool operator < (const edge & e) const{
            return weight  > e.weight;
    }
};

vector<edge> MST ;
priority_queue<edge> edgeList;
ll  kruskal(){
    ll minCost = 0;
    initialize(edgeList.size());
    while(!edgeList.empty()){
        edge e = edgeList.top();
        edgeList.pop();
        if(find_set(e.from)!= find_set(e.to)){
            minCost+=e.weight;
            Union(e.from,e.to);
            MST.push_back(e);
        }
    }
    return minCost;
}
int main()
{
    ll n , m ;
    cin >> n >> m ;
    for(ll i=0;i<m;i++){
        ll a , b , c ;
        cin >> a >> b >> c ;
        edgeList.push(edge(--a,--b,c));
    }
    ll minCost = kruskal();
    cout << minCost;
    return 0;
}
