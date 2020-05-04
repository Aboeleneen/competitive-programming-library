#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
    (1)order for dfs equal edges+nodes
    (2)order fro connectedCompontentsCnt edges+nodes
    (3) dag-> directed acycle graph
    (4) edge classification;
            tree edge
            back edge(cycle)
            forward edge
            cross edge
    (5) flood fill <maze>
*/
vector< vector <int> > adj ;
vector<bool> visited ;
vector<int> topSort ;
vector<int> start ;
vector<int>finish ;
int nodes , edges ;
void dfs(int node){
     visited[node]=true;
    //  cout << node << " " ;
     for(int i=0;i<adj[node].size();i++){
        int child = adj[node][i] ;
        if(! visited[child]){
             dfs(child) ;
        }
     }

     topSort.push_back(node);
}
int connectedComponentsCnt(){
      int cnt = 0 ;
      for(int i=1;i<=nodes;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
           // cout << cnt ;
        }
      }
      return cnt ;
}
void dfs_edge_classification(int node){

   start[node]=timer++ ;

   for(int i=0;i<adj[node].size();i++){
        int child = adj[node][i];
         if(start[child] == -1){
                dfs_edge_classification(child);
         } // not visited before <tree edge >
         else{
            if(finish[child] == -1) {
                anyCycle=1;
            } // back edge
            else if (start[node] < start[child]){

            } // forward edge
            else{

            } // cross edge
         }

   }
   finish[node]=timer++;


}
int cnt =0;


void cntReachableCells(int r , int c){

   if(!valid(r,c) || maze[r][c]='X' || vis[r][c] == 1) {
    return
   }

   vis[r][c] = 1 ;
   cnt++ ;

   cntReachableCells(r,c+1);
   cntReachableCells(r,c-1);
   cntReachableCells(r+1,c);
   cntReachableCells(r-1,c);

}

int main()
{
    adj = vector< vector<int> > (nodes) ;
    visited  = vector<bool>(nodes);
    start = vector<int>(nodes,-1);
    finish = vector<int>(nodes,-1);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[3].push_back(6);
    adj[3].push_back(7);
    adj[8].push_back(9);
    nodes=9;
    cout << "num: " << connectedComponentsCnt();
    return 0;
}
