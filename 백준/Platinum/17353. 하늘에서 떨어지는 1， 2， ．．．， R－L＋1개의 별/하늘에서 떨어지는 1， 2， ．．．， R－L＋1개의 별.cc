#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;

int n,q;
vector <ll> a,total,cnt,lazy_total,lazy_cnt;

void lazy_propagation_total(int node, int start, int end){
    if(lazy_total[node]!=0){
        total[node]+=lazy_total[node];
        if(start!=end){
            lazy_total[node*2]+=lazy_total[node];
            lazy_total[node*2+1]+=lazy_total[node];
        }
        lazy_total[node]=0;
    }
}

void update_total(int node, int start, int end, int left, int right, ll val){
    lazy_propagation_total(node,start,end);
    if(right<start || end<left){
        return;
    }
    if(left<=start && end<=right){
        lazy_total[node]+=val;
        lazy_propagation_total(node,start,end);
        return;
    }
    update_total(node*2,start,(start+end)/2,left,right,val);
    update_total(node*2+1,(start+end)/2+1,end,left,right,val);
}

void lazy_propagation_cnt(int node, int start, int end){
    if(lazy_cnt[node]!=0){
        cnt[node]+=lazy_cnt[node];
        if(start!=end){
            lazy_cnt[node*2]+=lazy_cnt[node];
            lazy_cnt[node*2+1]+=lazy_cnt[node];
        }
        lazy_cnt[node]=0;
    }
}

void update_cnt(int node, int start, int end, int left, int right){
    lazy_propagation_cnt(node,start,end);
    if(right<start || end<left){
        return;
    }
    if(left<=start && end<=right){
        lazy_cnt[node]++;
        lazy_propagation_cnt(node,start,end);
        return;
    }
    update_cnt(node*2,start,(start+end)/2,left,right);
    update_cnt(node*2+1,(start+end)/2+1,end,left,right);
}

ll query_total(int node, int start, int end, int left, int right){
    lazy_propagation_total(node,start,end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return total[node];
    }
    ll left_s=query_total(node*2,start,(start+end)/2,left,right);
    ll right_s=query_total(node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}

ll query_cnt(int node, int start, int end, int left, int right){
    lazy_propagation_cnt(node,start,end);
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return cnt[node];
    }
    ll left_s=query_cnt(node*2,start,(start+end)/2,left,right);
    ll right_s=query_cnt(node*2+1,(start+end)/2+1,end,left,right);
    return left_s+right_s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n+1));
    int tree_size=(1<<(h+2));
    a.resize(n+1);
    total.resize(tree_size);
    cnt.resize(tree_size);
    lazy_total.resize(tree_size);
    lazy_cnt.resize(tree_size);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int ck;
        cin >> ck;
        if(ck==1){
            int xx,yy;
            cin >> xx >> yy;
            update_total(1,1,n,xx,yy,xx);
            update_cnt(1,1,n,xx,yy);
        }
        else{
            int idx;
            cin >> idx;
            ll ans=query_cnt(1,1,n,idx,idx)*(idx+1)-query_total(1,1,n,idx,idx);
            cout << a[idx]+ans << '\n';
        }
    }
}