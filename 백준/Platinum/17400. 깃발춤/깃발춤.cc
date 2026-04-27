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
vector <ll> a,e_tree,o_tree;

void seg_tree(int node, int start, int end){
    if(start==end){
        if(start%2){
            o_tree[node]=a[start];
            e_tree[node]=-a[start];
        }
        else{
            o_tree[node]=-a[start];
            e_tree[node]=a[start];
        }
    }
    else{
        seg_tree(node*2,start,(start+end)/2);
        seg_tree(node*2+1,(start+end)/2+1,end);
        e_tree[node]=e_tree[node*2]+e_tree[node*2+1];
        o_tree[node]=o_tree[node*2]+o_tree[node*2+1];
    }
}

void update(int node, int start, int end, int idx, ll val){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        if(start%2){
            o_tree[node]+=val;
            e_tree[node]+=-val;
        }
        else{
            o_tree[node]+=-val;
            e_tree[node]+=val;
        }
        return;
    }
    update(node*2, start, (start+end)/2, idx, val);
    update(node*2+1, (start+end)/2+1, end, idx, val);
    e_tree[node]=e_tree[node*2]+e_tree[node*2+1];
    o_tree[node]=o_tree[node*2]+o_tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right, int ck){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        if(ck==0){
            return e_tree[node];
        }
        return o_tree[node];
    }
    ll left_sum=query(node*2,start,(start+end)/2,left,right,ck);
    ll right_sum=query(node*2+1,(start+end)/2+1,end,left,right,ck);
    return left_sum + right_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h=(int)ceil(log2(n));
    int tree_size=(1<<(h+1));
    a.resize(n);
    o_tree.resize(tree_size);
    e_tree.resize(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(1,0,n-1);
    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        if(q==1){
            int x,y;
            cin >> x >> y;
            if(x%2){
                cout << abs(query(1, 0, n-1, x-1, y-1,1)) << '\n';
            }
            else{
                cout << abs(query(1, 0, n-1, x-1, y-1,0)) << '\n';
            }

        }
        else{
            int x;
            ll y;
            cin >> x >> y;
            update(1, 0, n-1, x-1, y);
        }
    }
}