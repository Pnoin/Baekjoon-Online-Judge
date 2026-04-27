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

int n,m,k;
vector <ll> a,tree;

void Segment_Tree(int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        Segment_Tree(node*2,start,(start+end)/2);
        Segment_Tree(node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

void update(int node, int start, int end, int idx, ll val){
    if(start>idx || end<idx){
        return;
    }
    if(start==end){
        tree[node]=val;
        return; 
    }
    update(node*2,start,(start+end)/2,idx,val);
    update(node*2+1,(start+end)/2+1,end,idx,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right){
    if(start>right || end<left){
        return 0; 
    }
    if(start>=left && end<=right){
        return tree[node];
    }
    ll left_sum=query(node*2,start,(start+end)/2,left,right);
    ll right_sum=query(node*2+1,(start+end)/2+1,end,left,right);
    return left_sum+right_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n+1));
    int tree_size = (1<<(h+1));
    a.resize(n);
    tree.resize(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    Segment_Tree(1,0,n-1);
    cin >> m;
    for(int i=0; i<m; i++){
        int xx,yy;
        cin >> xx >> yy;
        cout << query(1,0,n-1,xx-1,yy-1) << '\n';
    }
} 