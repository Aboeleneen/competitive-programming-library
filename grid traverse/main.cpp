#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n ;
ll grid[3][3];
bool valid(ll r , ll c){
  return r>=0&&c>=0&&r<n&&c<n ;
  }
ll maxPathSum(ll r , ll c ){
   if(!valid(r,c)){
    return  0 ;
   }

   if(r == n-1 && c == n-1){
      return grid[r][c] ; // base
   }

   ll path1 = maxPathSum(r,c+1) ;// right
   ll path2 = maxPathSum(r+1,c) ;// down

  //  cout << grid[r][c] << " " << path1 << " " << path2 << endl ;

   return grid[r][c]+ max(path1,path2) ;
}

// we can use DP because sub_problems overlap
ll DP[3][3]={0};
ll maxPathSum_dp(ll r , ll c ){
   if(!valid(r,c)){
    return  0 ;
   }

   if(r == n-1 && c == n-1){
      return grid[r][c] ; // base
   }

   if(DP[r][c] != 0){
      return DP[r][c] ;
   }

   ll path1 = maxPathSum(r,c+1) ;// right
   ll path2 = maxPathSum(r+1,c) ;// down

  //  cout << grid[r][c] << " " << path1 << " " << path2 << endl ;

   return DP[r][c]=grid[r][c]+ max(path1,path2) ;
}
int main()
{

    cin >> n ;
    for(ll i=0;i<n;i++){
        for( ll j=0;j<n;j++){
            cin >> grid[i][j] ;
        }
    }
    cout << maxPathSum_dp(0,0);
    return 0;
}
