#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// goal of segment tree is control sub intervals and apply queries on them
// may you need a dynamic array with insert and delete operations
vector<ll> input;
vector<ll> segment_tree;
void construct(ll low , ll high , ll pos){
    if(low==high){
        segment_tree.at(pos)=input.at(left);
    }
    ll mid = (low+high)/2;
    construct(low,mid,2*pos+1);
    construct(mid+1,high,2*pos+2);
    // internal node value change due to problem context
    segment_tree.at(pos) = min(segment_tree.at(2*pos+1) , segment_tree.at(2*pos+2));
}
ll query(ll qlow , ll qhigh , ll low , ll high , ll pos){
    // total overlap
    if(qlow>=low&&qhigh<=high){
        return segment_tree.at(pos);
    }
    // no overlap
    if(low>qhigh || high < qlow){
        // change to context
    }
    // partial overlap
    ll mid = (high+low)/2;
    ll left = query(qlow,qhigh,low,mid,2*pos+1);
    ll right = query(qlow,qhigh,mid+1,high,2*pos+2)
    return min(left,right)
}
void update(){
}
int main()
{

    return 0;
}
