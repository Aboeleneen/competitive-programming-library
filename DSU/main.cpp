#include <iostream>
#include<bits/stdc++.h>
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
int fint_set(int n){
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
void union(int x , int y){
    int parentX = find_set(x);
    int parentY = find_set(y);
    if(parentX==parentY) return;
    link(parentX,parentY);
    parent[parentX]=parentY;
}
int main()
{

    return 0;
}


