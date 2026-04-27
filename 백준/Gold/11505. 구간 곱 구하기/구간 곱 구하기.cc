#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long int ll;

int n,m,k,md=1e9+7;

void seg_tree(vector <ll> &a, vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node]=(tree[node*2]*tree[node*2+1])%md;
    }
}

ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 1;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_sum=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_sum=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return (left_sum * right_sum)%md;
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
    tree[node]=(tree[node*2]*tree[node*2+1])%md;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <ll> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(a,tree,1,0,n-1);
    for(int i=0; i<m+k; i++){
        int ck;
        cin >> ck;
        if(ck==1){
            int x;
            ll y;
            cin >> x >> y;
            update(tree, 1, 0, n-1, x-1, y);
        }
        else if(ck==2){
            int x,y;
            cin >> x >> y;
            cout << query(tree, 1, 0, n-1, x-1, y-1) << '\n';
        }
    }
}