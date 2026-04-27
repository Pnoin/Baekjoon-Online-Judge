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
        tree[node]=tree[node*2]*tree[node*2+1];
    }
}

/// 쿼리 1
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
    tree[node]=tree[node*2]*tree[node*2+1];
}

/// 쿼리 2
ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 1;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_min=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_min=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return left_min*right_min;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n >> m){
        int h=(int)ceil(log2(n));
        int tree_size = (1 << (h+1));
        vector <ll> a(n);
        vector <ll> tree(tree_size);
        for(int i=0; i<n; i++){
            ll num; 
            cin >> num;
            if(num==0){
                a[i]=0;
            }
            else if(num>0){
                a[i]=1;
            }
            else{
                a[i]=-1;
            }
        }
        /// 세그 트리 생성
        seg_tree(a,tree,1,0,n-1);
        /// 쿼리 입력
        for(int i=0; i<m; i++){
            char ck;
            cin >> ck;
            /// 쿼리 1 업데이트
            if(ck=='C'){
                int x;
                ll y;
                cin >> x >> y;
                if(y<0){
                    y=-1;
                }
                else if(y>0){
                    y=1;
                }
                update(tree, 1, 0, n-1, x-1, y);
            }
            /// 쿼리 2 
            else if(ck=='P'){
                int xx,yy; 
                cin >> xx >> yy;
                ll temp=query(tree, 1, 0, n-1, xx-1, yy-1);
                if(temp==0){
                    cout << 0;
                }
                else if(temp<0){
                    cout << '-';
                }
                else{
                    cout << '+';
                }
            }
        }
        cout << '\n';
    }
}