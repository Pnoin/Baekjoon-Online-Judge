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
        if(a[start]==0){
            tree[node]=1;
            tree2[node]=0;
        }
        else{
            tree[node]=0;
            tree2[node]=1;
        }
    }
    else{
        seg_tree(a,tree,tree2,node*2,start,(start+end)/2);
        seg_tree(a,tree,tree2,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
        tree2[node]=tree2[node*2]+tree2[node*2+1];
    }
}

/// 쿼리 2
ll odd_query(vector <ll> &tree, vector <ll> &tree2, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree2[node];
    }
    ll left_o=odd_query(tree,tree2,node*2,start,(start+end)/2,left,right);
    ll right_o=odd_query(tree,tree2,node*2+1,(start+end)/2+1,end,left,right);
    return left_o+right_o;
}

/// 쿼리 2
ll even_query(vector <ll> &tree, vector <ll> &tree2, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_e=even_query(tree,tree2,node*2,start,(start+end)/2,left,right);
    ll right_e=even_query(tree,tree2,node*2+1,(start+end)/2+1,end,left,right);
    return left_e+right_e;
}

/// 쿼리 1
void update(vector <ll> &tree, vector <ll> &tree2, int node, int start, int end, int idx, ll val){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        if(val%2==0){
            tree[node]=1;
            tree2[node]=0;
        }
        else{
            tree[node]=0;
            tree2[node]=1;
        }
        return;
    }
    update(tree, tree2, node*2, start, (start+end)/2, idx, val);
    update(tree, tree2, node*2+1, (start+end)/2+1, end, idx, val);
    tree[node]=tree[node*2]+tree[node*2+1];
    tree2[node]=tree2[node*2]+tree2[node*2+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <ll> a(n);
    vector <ll> tree(tree_size); ///짝
    vector <ll> tree2(tree_size); ///홀
    for(int i=0; i<n; i++){
        ll num;
        cin >> num;
        if(num%2==0){
            a[i]=0;
        }
        else{
            a[i]=1;
        }
    }
    /// 세그 트리 생성
    seg_tree(a,tree,tree2,1,0,n-1);

    /// 쿼리 입력
    cin >> m;
    for(int i=0; i<m; i++){
        int ck;
        cin >> ck;
        /// 쿼리 1 업데이트
        if(ck==1){
            int x;
            ll y;
            cin >> x >> y;
            update(tree, tree2, 1, 0, n-1, x-1, y);
        }
        /// 쿼리 2
        else{
            int xx,yy; 
            cin >> xx >> yy;
            if(ck==2){
                cout << even_query(tree, tree2, 1, 0, n-1, xx-1, yy-1) << '\n';
            }
            else{
                cout << odd_query(tree, tree2, 1, 0, n-1, xx-1, yy-1) << '\n';
            }
        }
    }
}