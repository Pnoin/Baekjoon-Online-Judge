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

int n,m;

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
    if(lazy[node]%2==1){
        tree[node]=(end-start+1)-tree[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(vector <ll> &tree, vector <ll> &lazy, int node, int start, int end, int left, int right){
    lazy_propagation(tree, lazy, node, start, end);
    if(right < start || left > end){
        return;
    }
    if(left<=start && right>=end){
        lazy[node]++;
        lazy_propagation(tree, lazy, node, start, end);
        return;
    }
    update(tree, lazy, node*2, start, (start+end)/2, left, right);
    update(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
    tree[node]=tree[node*2]+tree[node*2+1];
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h=(int)ceil(log2(n));
    int tree_size=(1<<(h+1));
    vector <ll> tree(tree_size);
    vector <ll> lazy(tree_size);
    seg_tree(tree,1,0,n-1);
    for(int i=0; i<m; i++){
        int ck,x,y;
        cin >> ck >> x >> y;
        if(ck==0){
            update(tree, lazy, 1, 0, n-1, min(x-1, y-1), max(x-1, y-1));
        }
        else if(ck==1){
            cout << query(tree, lazy, 1, 0, n-1, min(x-1, y-1), max(x-1, y-1)) << '\n';
        }
    }
}