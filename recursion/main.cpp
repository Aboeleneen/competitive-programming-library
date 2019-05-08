#include <iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;
bool vis[MAX][MAX];
ll n , m ;
bool valid(ll r , ll c){
 return r>=0&&c>=0&&r<n&&c<m;
}
bool findEnd(ll r ,ll c){

    cout << r << " " << c  << endl ;
   if(!valid(r,c) || maze[r][c] == 'X' || vis[r][c]==1)
      return false ;


    vis[r][c]=1;

   if(maze[r][c]=='E')
        return true ;

        // try for 4 neighbors
    if(findEnd(r,c-1)) return true ; // search up
    if(findEnd(r,c+1)) return true ; // search down
    if(findEnd(r-1,c)) return true ; // search left
    if(findEnd(r+1,c)) return true ; // search right

    vis[r][c]=0;

    // can't find a way to end
    return false ;
}

ll cnt = 0 ;
void cntReachableCells(ll r , ll c ){

   if(!valid(r,c) || maze[r][c] == 'X' || vis[r][c] == 1)
    return;

   vis[r][c]=1;
   cnt++;
   cntReachableCells(r,c-1);
   cntReachableCells(r,c+1);
   cntReachableCells(r-1,c);
   cntReachableCells(r+1,c);
}

ll comp=0 ;
void cntComponents(ll r , ll c ){

   for(ll i=0;i<r;i++){
    for(ll j=0;j<c;j++){
        cnt=0;
        cntReachableCells(i,j);

        if(cnt>0) comp++;
    }
   }
}

void generateBinary(ll len , string cur = ""){
  if(len == 0){
    cout << cur << endl ;
    return ;
  }

  generateBinary(len-1,cur + "0");
  generateBinary(len-1,cur + "1");
}

void perm(ll i , ll n , ll vis[] , ll cur[]){

     if(i==n+1){

        for(ll j=1;j<=n;j++){
            cout << cur[j] << " ";
        }
        cout << "\n";
        return;
     }

     for(ll j=1;j<=n;j++) if(vis[j]==0)
     {

         vis[j]=1;
         cur[i]=j;

         perm(i+1,n,vis,cur);

         vis[j]=0;
     }

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
