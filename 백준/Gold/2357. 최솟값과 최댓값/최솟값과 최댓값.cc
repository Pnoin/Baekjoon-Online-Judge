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

void seg_tree(vector <ll> &a, vector <ll> &tree, vector <ll> &tree2, int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
        tree2[node]=a[start];
    }
    else{
        seg_tree(a,tree,tree2,node*2,start,(start+end)/2);
        seg_tree(a,tree,tree2, node*2+1,(start+end)/2+1,end);
        tree[node]=min(tree[node*2],tree[node*2+1]);
        tree2[node]=max(tree2[node*2],tree2[node*2+1]);
    }
}

ll min_query(vector <ll> &tree, vector <ll> &tree2, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 1e9+1;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_min=min_query(tree,tree2, node*2,start,(start+end)/2,left,right);
    ll right_min=min_query(tree,tree2, node*2+1,(start+end)/2+1,end,left,right);
    return min(left_min, right_min);
}

ll max_query(vector <ll> &tree, vector <ll> &tree2, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree2[node];
    }
    ll left_max=max_query(tree,tree2, node*2,start,(start+end)/2,left,right);
    ll right_max=max_query(tree,tree2, node*2+1,(start+end)/2+1,end,left,right);
    return max(left_max, right_max);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h=(int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <ll> tree(tree_size);
    vector <ll> tree2(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /// 세그 트리 생성
    seg_tree(a,tree,tree2,1,0,n-1);
    for(int i=0; i<m; i++){
        int x,y; 
        cin >> x >> y;
        cout << min_query(tree, tree2, 1, 0, n-1, x-1, y-1) << ' ' << max_query(tree, tree2, 1, 0, n-1, x-1, y-1) << '\n';
    }
}