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

int n,m;

void seg_tree(vector <ll> &a, vector <pll> &tree, int node, int start, int end){
    if(start==end){
        tree[node].first=a[start];
        tree[node].second=start;
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        if(tree[node*2].first > tree[node*2+1].first){
            tree[node].first=tree[node*2+1].first;
            tree[node].second=tree[node*2+1].second;
        }
        else if(tree[node*2].first < tree[node*2+1].first){
            tree[node].first=tree[node*2].first;
            tree[node].second=tree[node*2].second;
        }
        else{
            tree[node].first=tree[node*2+1].first;
            tree[node].second=min(tree[node*2].second, tree[node*2+1].second);
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
    if(tree[node*2].first > tree[node*2+1].first){
        tree[node].first=tree[node*2+1].first;
        tree[node].second=tree[node*2+1].second;
    }
    else if(tree[node*2].first < tree[node*2+1].first){
        tree[node].first=tree[node*2].first;
        tree[node].second=tree[node*2].second;
    }
    else{
        tree[node].first=tree[node*2+1].first;
        tree[node].second=min(tree[node*2].second, tree[node*2+1].second);
    }
}

pll query(vector <pll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return {1e9+1, 1e9+1};
    }
    if(left <= start && right >= end){
        return {tree[node].first, tree[node].second};
    }
    pll left_min=query(tree,node*2,start,(start+end)/2,left,right);
    pll right_min=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    if(left_min.first > right_min.first){
        return {right_min.first, right_min.second};
    }
    else if(left_min.first < right_min.first){
        return {left_min.first, left_min.second};
    }
    else{
        return {left_min.first, min(left_min.second, right_min.second)};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n));
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
            int xx,yy; 
            cin >> xx >> yy;
            cout << query(tree, 1, 0, n-1, xx-1, yy-1).second + 1 << '\n';
        }
    }
}