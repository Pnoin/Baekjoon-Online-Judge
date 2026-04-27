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
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}

ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_max=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_max=query(tree,node*2+1,(start+end)/2+1,end,left,right);
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
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /// 세그 트리 생성
    seg_tree(a,tree,1,0,n-1);

    /// 쿼리 입력
    for(int i=m-1; i<n-m+1; i++){
        cout << query(tree, 1, 0, n-1, i-m+1, i+m-1) << ' ';
    }
}