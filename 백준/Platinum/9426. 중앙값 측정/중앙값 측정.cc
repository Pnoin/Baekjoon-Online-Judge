#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;

int n,k,mx=66000,ck=0;
vector <ll> a,tree;
ll total=0;


void Segment_Tree(int node, int start, int end){
    if(start==end){
        tree[node]=0;
    }
    else{
        Segment_Tree(node*2,start,(start+end)/2);
        Segment_Tree(node*2+1,(start+end)/2+1,end);
    }
}


void update(int node, int start, int end, int idx, ll val){
    if(start>idx || end<idx){
        return;
    }
    if(start==end){
        tree[node]+=val;
        return; 
    }
    update(node*2,start,(start+end)/2,idx,val);
    update(node*2+1,(start+end)/2+1,end,idx,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int start, int end, int v){
    if(start==end){
        return start;
    }
    if(v>tree[node*2]){
        return query(node*2+1,(start+end)/2+1,end,v-tree[node*2]);
    }
    return query(node*2,start,(start+end)/2,v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int h=(int)ceil(log2(mx+1));
    int tree_size=(1<<(h+1));
    a.resize(n);
    tree.resize(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    Segment_Tree(1,0,mx);
    for(int i=0; i<n; i++){
        update(1,0,mx,a[i],1);
        if(i>=k-1){
            if(ck==1){
                update(1,0,mx,a[i-k],-1);
            }
            total+=query(1,0,mx,(k+1)/2);
            ck=1;
        }
    }
    cout << total;
} 