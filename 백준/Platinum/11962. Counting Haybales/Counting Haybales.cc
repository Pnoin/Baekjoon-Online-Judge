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

void seg_tree(vector <ll> &a, vector <ll> &tree, vector <ll> &tree2,int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
        tree2[node]=a[start];
    }
    else{
        seg_tree(a,tree,tree2,node*2,start,(start+end)/2);
        seg_tree(a,tree,tree2,node*2+1,(start+end)/2+1,end);
        tree[node]=tree[node*2]+tree[node*2+1];
        tree2[node]=min(tree2[node*2],tree2[node*2+1]);
    }
}

/// 느리게 갱신
void lazy_propagation(vector <ll> &tree, vector <ll> &tree2, vector <ll> &lazy, int node, int start, int end) {
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        tree2[node]+=lazy[node];
        if (start!=end) { ///리프 노드가 아닐 경우
            /// 자식 노드에게 전파
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        /// 전파 끝
        lazy[node]=0;
    }
}

/// 쿼리 1
void update(vector <ll> &tree, vector <ll> &tree2, vector <ll> &lazy, int node, int start, int end, int left, int right, ll val){
    lazy_propagation(tree, tree2, lazy, node, start, end);
    if(right < start || left > end){
        return;
    }
    /*
        특정 노드의 값을 바꾸는 게 아니라 특정 구간의 값을 바꾸는 거기 때문에 start==end일 때를 보는게 아니라 left<=start && right>=end인 구간을 봐야함.
        예시) 
        1 ~ 5
        1 2 3 4 5 (index)
        근데 2~3 구간을 바꾸고 싶대

        그러면 각 변수는 
        start, end = 1,5
        left, right = 2,3

        left랑 right는 (바꾸고 싶은 구간) 고정이고, 이분탐색마냥 start랑 end만 계속 바뀜 
        즉, left <= start && right >= end 이라는 건, start와 end가 left와 right 범위 안에 들어왓다는 거니까
        여기가 이제 '느리게 갱신' 받아야하는 구간이 되었다는 것
    */
    if(left<=start && right>=end){
        lazy[node]+=val;
        lazy_propagation(tree, tree2, lazy, node, start, end);
        return;
    }   
    update(tree, tree2, lazy, node*2, start, (start+end)/2, left, right, val);
    update(tree, tree2, lazy, node*2+1, (start+end)/2+1, end, left, right, val);
    tree[node]=tree[node*2]+tree[node*2+1];
    tree2[node]=min(tree2[node*2],tree2[node*2+1]);
}

/// 합 쿼리
ll query(vector <ll> &tree,vector <ll> &tree2, vector <ll> &lazy, int node, int start, int end, int left, int right){
    lazy_propagation(tree, tree2,lazy, node, start, end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,tree2,lazy,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,tree2,lazy,node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}

/// 최소 쿼리
ll min_query(vector <ll> &tree, vector <ll> &tree2, vector <ll> &lazy, int node, int start, int end, int left, int right){
    lazy_propagation(tree, tree2, lazy, node, start, end);
    if(left > end || start > right){
        return 1e9+1;
    }
    if(left <= start && right >= end){
        return tree2[node];
    }
    ll left_min=min_query(tree,tree2,lazy,node*2,start,(start+end)/2,left,right);
    ll right_min=min_query(tree,tree2,lazy,node*2+1,(start+end)/2+1,end,left,right);
    return min(left_min,right_min);
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
    vector <ll> tree2(tree_size);
    vector <ll> lazy(tree_size);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    /// 세그 트리 생성
    seg_tree(a,tree,tree2,1,0,n-1);
    /// 쿼리 입력
    for(int i=0; i<m; i++){
        char ck;
        cin >> ck;
        /// 쿼리 1 업데이트
        if(ck=='P'){
            int x,y;
            ll z;
            cin >> x >> y >> z;
            update(tree, tree2, lazy, 1, 0, n-1, x-1, y-1, z);
        }
        /// 쿼리 2 
        else if(ck=='S'){
            int xx,yy; 
            cin >> xx >> yy;
            cout << query(tree, tree2, lazy, 1, 0, n-1, xx-1, yy-1) << '\n';
        }
        else{
            int xx,yy; 
            cin >> xx >> yy;
            cout << min_query(tree, tree2, lazy, 1, 0, n-1, xx-1, yy-1) << '\n';
        }
    }
}