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

int n,m,q;

void seg_tree(vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=0;
    }
    else{
        seg_tree(tree,node*2,start,(start+end)/2);
        seg_tree(tree,node*2+1,(start+end)/2+1,end);
    }
}

void lazy_propagation(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end) {
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if (start!=end) {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right, ll val){
    lazy_propagation(tree, lazy, node, start, end);
    if(right < start || left > end){
        return;
    }
    if(left<=start && right>=end){
        lazy[node]+=val;
        lazy_propagation(tree, lazy, node, start, end);
        return;
    }
    update(tree, lazy, node*2, start, (start+end)/2, left, right, val);
    update(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

void seg_tree2(vector <ll> &tree2, int node, int start, int end){
    if(start==end){
        tree2[node]=0;
    }
    else{
        seg_tree2(tree2,node*2,start,(start+end)/2);
        seg_tree2(tree2,node*2+1,(start+end)/2+1,end);
    }
}

void lazy_propagation2(vector <ll> &tree2, vector <ll> &lazy2, int node, int start, int end) {
    if(lazy2[node]!=0){
        tree2[node]+=(end-start+1)*lazy2[node];
        if (start!=end) {
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2+1]+=lazy2[node];
        }
        lazy2[node]=0;
    }
}

void update2(vector <ll> &tree2, vector <ll> &lazy2, int node, int start, int end, int left, int right, ll val){
    lazy_propagation2(tree2, lazy2, node, start, end);
    if(right < start || left > end){
        return;
    }
    if(left<=start && right>=end){
        lazy2[node]+=val;
        lazy_propagation2(tree2, lazy2, node, start, end);
        return;
    }
    update2(tree2, lazy2, node*2, start, (start+end)/2, left, right, val);
    update2(tree2, lazy2, node*2+1, (start+end)/2+1, end, left, right, val);
    tree2[node]=tree2[node*2]+tree2[node*2+1];
}

ll query(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right){
    lazy_propagation(tree, lazy, node, start, end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,lazy,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,lazy,node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}

ll query2(vector <ll> &tree2, vector <ll> &lazy2, int node, int start, int end, int left, int right){
    lazy_propagation2(tree2, lazy2, node, start, end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree2[node];
    }
    ll left_s=query2(tree2,lazy2,node*2,start,(start+end)/2,left,right);
    ll right_s=query2(tree2,lazy2,node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    int h=(int)ceil(log2(n*m));
    int tree_size = (1 << (h+1));
    ll arr[n][m]={};
    vector <ll> tree(tree_size);
    vector <ll> tree2(tree_size);
    vector <ll> lazy(tree_size);
    vector <ll> lazy2(tree_size);
    seg_tree(tree,1,0,n*m-1);
    seg_tree(tree2,1,0,n*m-1);
    for(int i=0; i<q; i++){
        int ck,where,val;
        cin >> ck >> where >> val;
        if(ck==1){
            update(tree, lazy, 1, 0, n*m-1, (where-1)*m, (where*m)-1, val);
        }
        else{
            update2(tree2, lazy2, 1, 0, n*m-1, (where-1)*n, (where*n)-1, val);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[i][j]+=query(tree, lazy, 1, 0, n*m-1,i*m+j, i*m+j);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[j][i]+=query2(tree2, lazy2, 1, 0, n*m-1,i*n+j, i*n+j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}