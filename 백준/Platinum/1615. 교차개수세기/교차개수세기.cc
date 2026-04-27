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

int n,m,temp,temp2;
ll ans=0;


void seg_tree(vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=0;
    }
    else{
        seg_tree(tree,node*2,start,(start+end)/2);
        seg_tree(tree,node*2+1,(start+end)/2+1,end);
    }
}

void update(vector <ll> &tree, int node, int start, int end, int idx){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        tree[node]+=1;
        return; 
    }
    update(tree, node*2, start, (start+end)/2, idx);
    update(tree, node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return left_s + right_s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h=(int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> tree(tree_size);
    vector <int> v[n+1];
    seg_tree(tree,1,0,n-1);
    for(int i=0; i<m; i++){
        cin >> temp >> temp2;
        v[temp].push_back(temp2);
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<v[i].size(); j++){
            ans+=query(tree, 1, 0, n-1, v[i][j], n-1);
        }
        for(int j=0; j<v[i].size(); j++){
            update(tree, 1, 0, n-1, v[i][j]-1);
        }
    }
    cout << ans;
}