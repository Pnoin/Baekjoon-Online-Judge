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
typedef pair<ll,ll> pll;

int n,m,k;

void seg_tree(vector <ll> &a, vector <pll> &tree, int node, int start, int end){
    if(start==end){
        tree[node].first=a[start];
        tree[node].second=start;
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        tree[node].first=max(tree[node*2].first,tree[node*2+1].first);
        if(tree[node*2].first<=tree[node*2+1].first){
            tree[node].second=tree[node*2+1].second;
        }
        else{
            tree[node].second=tree[node*2].second;
        }
    }
}

void update(vector <pll> &tree, int node, int start, int end, int idx, ll val){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        tree[node].first=val;
        return;
    }
    update(tree, node*2, start, (start+end)/2, idx, val);
    update(tree, node*2+1, (start+end)/2+1, end, idx, val);
    tree[node].first=max(tree[node*2].first,tree[node*2+1].first);
    if(tree[node*2].first<=tree[node*2+1].first){
        tree[node].second=tree[node*2+1].second;
    }
    else{
        tree[node].second=tree[node*2].second;
    }
}

pll query(vector <pll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return {0,0};
    }
    if(left <= start && right >= end){
        return {tree[node].first,tree[node].second};
    }
    pll left_max=query(tree,node*2,start,(start+end)/2,left,right);
    pll right_max=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    if(left_max.first<=right_max.first){
        return right_max;
    }
    else{
        return left_max;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <pll> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(a,tree,1,0,n-1);
    cin >> m;
    for(int i=0; i<m; i++){
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
            ll total=query(tree, 1, 0, n-1, x-1, y-1).first;
            int tempidx=query(tree, 1, 0, n-1, x-1, y-1).second;
            if(tempidx==x-1){
                total+=query(tree, 1, 0, n-1, x, y-1).first;
            }
            else if(tempidx==y-1){
                total+=query(tree, 1, 0, n-1, x-1, y-2).first;
            }
            else{
                total+=max(query(tree, 1, 0, n-1, x-1, tempidx-1).first,query(tree, 1, 0, n-1, tempidx+1, y-1).first);
            }
            cout << total << '\n';
        }
    }
}