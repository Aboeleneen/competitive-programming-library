#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll countPath = 0 ;
ll n , m ;
char maze[100][100] ;
bool valid(ll r,ll c){
    return r>=0&&c>=0&&r<n&&c<m;
}
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
/*
 * if maze contain only S,E,. then O(exponential)
 * problem need to find one path between S and E then we cancel undo step-->flood fill
 *
*/
void count_paths_maze(ll r , ll c ){
    if(!valid(r,c))
        return ;
    if(maze[r][c]=='E'){
        countPath++;
        return;
    }
   // maze[r][c]='#';
    for(ll i=0;i<4;i++){
        ll nr = r+dx[i];
        ll nc = r+dy[i];
        if(valid(nr,nc)&&(maze[nr][nc]=='.'||maze[nr][nc]=='E')){
            if(maze[nr][nc]!='E'){
                maze[nr][nc]='X'; // do
            }
            count_paths_maze(nr,nc); // rec
            if(maze[nr][nc]!='E'){
                maze[nr][nc]='.'; // undo
            }
        }
    }

}
string test="123" ;
void string_per(ll num , string cur){
     if(cur.length()==test.length()){
        cout << cur << endl ;
        return ;
     }
     for(ll i=0;i<test.length();i++){
        char newOne = test[i];
        if(test[i]!='#'){
            test[i]='#';
            string_per(i,cur+newOne);
        }

        if(test[i]=='#'){
            test[i]=newOne;
        }
     }
}
int main()
{
    string_per(0,"");
    return 0;
}
