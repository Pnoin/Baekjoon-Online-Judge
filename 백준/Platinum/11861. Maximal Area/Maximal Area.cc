/// 히스토그램이랑 같은 거 같은데
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

int n;

void seg_tree(vector <ll> &a, vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=start;
    }
    else{
        seg_tree(a,tree,node*2,start,(start+end)/2);
        seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        if(a[tree[node*2]]<=a[tree[node*2+1]]){
            tree[node]=tree[node*2];
        }
        else{
            tree[node]=tree[node*2+1];
        }
    }
}

ll query(vector <ll> &a, vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return -1;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_idx=query(a,tree,node*2,start,(start+end)/2,left,right);
    ll right_idx=query(a,tree,node*2+1,(start+end)/2+1,end,left,right);
    if(right_idx==-1){
        return left_idx;
    }
    else if(left_idx==-1){
        return right_idx;
    }
    else if(a[left_idx]<=a[right_idx]){
        return left_idx;
    }
    else{
        return right_idx;
    }
}

ll mx(vector <ll> &a, vector <ll> &tree, int start, int end){
    ll idx=query(a,tree,1,0,n-1,start,end), ans=(end-start+1)*a[idx];
    if(start<=idx-1){
        ans=max(ans, mx(a,tree,start,idx-1));
    }
    if(idx+1<=end){
        ans=max(ans, mx(a,tree,idx+1,end));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <ll> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    seg_tree(a,tree,1,0,n-1);
    cout << mx(a,tree,0,n-1);
}