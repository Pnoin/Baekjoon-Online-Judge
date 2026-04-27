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

void seg_tree(vector <ll> &a, vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_sum=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_sum=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return left_sum + right_sum;
}

void update(vector <ll> &tree, int node, int start, int end, int idx, ll val){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        tree[node]=val;
        return;
    }
    update(tree, node*2, start, (start+end)/2, idx, val);
    update(tree, node*2+1, (start+end)/2+1, end, idx, val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <ll> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(a,tree,1,0,n-1);
    for(int i=0; i<m; i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        cout << query(tree, 1, 0, n-1, min(x-1,y-1), max(x-1,y-1)) << '\n';
        update(tree, 1, 0, n-1, a-1, b);        
    }
}