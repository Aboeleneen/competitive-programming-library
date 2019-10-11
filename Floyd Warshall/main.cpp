#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define OO 1e7+7
using namespace std;
//Floyd Warshall algorithm be used to get all pairs shortest path
// it uses dynamic programming O(n^3)
// we can use dijkstra algorithm on each vertex
int main()
{
    ll n , m ;
    cin >> n >> m ;
    ll graph[n][n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            graph[i][j]=OO;
            if(i==j) graph[i][j]=0;
        }
    }
    for(ll i=0;i<m;i++){
        ll a , b , c ;
        cin >> a >> b >> c ;
        a--;
        b--;
        graph[a][b]=c;
    }
    for(ll k=0;k<n;k++){
        for(ll i=0;i<n;i++){
            if(i==k) continue;
            for(ll j=0;j<n;j++){
                if(j==k) continue;
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    return 0;
}
