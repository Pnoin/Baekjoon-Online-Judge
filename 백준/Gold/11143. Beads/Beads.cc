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

int n,p,q,t;

void seg_tree(vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=0;
    }
    else{
        seg_tree(tree,node*2,start,(start+end)/2);
        seg_tree(tree,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}

/// 쿼리 1
void update(vector <ll> &tree, int node, int start, int end, int idx, ll val){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        tree[node]+=val;
        return;
    }
    update(tree, node*2, start, (start+end)/2, idx, val);
    update(tree, node*2+1, (start+end)/2+1, end, idx, val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

/// 쿼리 2
ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n >> p >> q;
        int h=(int)ceil(log2(n));
        int tree_size = (1 << (h+1));
        vector <ll> tree(tree_size);
        /// 세그 트리 생성
        seg_tree(tree,1,0,n-1);
        /// 쿼리 입력
        for(int i=0; i<p+q; i++){
            char ck;
            cin >> ck;
            /// 쿼리 1 업데이트
            if(ck=='P'){
                int x;
                ll y;
                cin >> x >> y;
                update(tree, 1, 0, n-1, x-1, y);
            }
            /// 쿼리 2 
            else if(ck=='Q'){
                int xx,yy; 
                cin >> xx >> yy;
                cout << query(tree, 1, 0, n-1, xx-1, yy-1) << '\n';
            }
        }
    }
}