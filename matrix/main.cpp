#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define row vector<ll>
#define matrix vector<row>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
matrix zeros(ll n , ll m ){
   return matrix(n,row(m,0));
}
matrix identity(ll n){
       matrix I = zeros(n,n);
       rep(i,n) I[i][i]=1;
       return I ;
}
// sum of diagonal elements
ll matrixTrace(matrix a){
   ll sum = 0 ;
   rep(i,a.size()) sum+=a[i][i];
   return sum;
}
/*
 *
 * 1 7 9  --->  0 1
 * 0 9 4  --->  9 7
 *              4 9
 */
matrix rotate(matrix &v){
   ll rows = v.size();
   ll col = v[0].size();
   matrix ret = zeros(col,rows);
   rep(i,rows)
        rep(j,col)
            ret[j][rows-i-1]=v[i][j];
    return ret;
}
//  1 2 3 --->  3 2 1
//  4 5 6 --->  6 5 4
//  call by reference
matrix reflect(matrix &v){
    ll rows = v.size();
    ll col = v[0].size();
    matrix ret = zeros(rows,col);
    rep(i,rows)
        rep(j,col)
            ret[i][col-j-1]=v[i][j];
    return ret;
}
matrix add(matrix &a,matrix &b){
    ll rows = a.size();
    ll cols = a[0].size();
    matrix rep = zeros(rows,cols);
    rep(i,rows)
        rep(j,cols)
            rep[i][j]=a[i][j]+b[i][j];
    return rep ;
}
matrix addIdentity(matrix &a){
   ll rows = a.size();
   matrix ret = a ;
   rep(i,rows)  ret[i][i]=a[i][i]+1;
   return ret;
}
// O(n^3)
matrix multiply(matrix &a, matrix &b){
   ll rows = a.size();
   ll cols = b[0].size();
   ll iter = a[0].size();
   matrix ret  = zeros(rows,cols);
   rep(i,rows)
        rep(j,cols)
            rep(k,iter)
                ret[i][j]+=(a[i][k]*b[k][j]);
    return ret ;
}

// O(log(n)*n^3)
matrix pow(matrix &a,ll p){
  if(p==0)
    return identity(a.size());
  matrix st = pow(a,p/2);
  st=multiply(st,st);

  if(p%2==1)
      st=multiply(st,a);

  return st ;
}
// i have a problem with this
/*matrix sumPow(matrix a,ll k){
   if(k==0)
        return zeros(a.size(),a.size());
   if(k%2==1)
        return multiply(a,addIdentity(sumPow(a,k-1)));
   return multiply(sumPow(a,k/2),addIdentity(pow(a,k/2)));
}*/

int main()
{
    matrix a ;
    row v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    a.push_back(v);
    v.clear();

    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    a.push_back(v);
    v.clear();
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    a.push_back(v);
    matrix res = pow(a,3);
    rep(i,res.size()){
        rep(j,res[0].size()){
           cout << res[i][j] << " " ;
        }
        cout << endl ;
    }


}
