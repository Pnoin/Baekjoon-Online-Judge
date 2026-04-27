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
vector <int> a,tree[275000];  //max val of n = 100000 --> max val of tree_size = 262144

void update(int node, int start, int end, int idx, int val){
    if(start>idx || end<idx){
        return;
    }
    if(start==end){
        tree[node].push_back(val);
        return; 
    }
    tree[node].push_back(val);
    update(node*2,start,(start+end)/2,idx,val);
    update(node*2+1,(start+end)/2+1,end,idx,val);
}

int query(int node, int start, int end, int left, int right, int val){
    if(start>right || end<left){
        return 0; 
    }
    if(start>=left && end<=right){
        return tree[node].size()-(upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin());
    }
    ll left_mx=query(node*2,start,(start+end)/2,left,right,val);
    ll right_mx=query(node*2+1,(start+end)/2+1,end,left,right,val);
    return left_mx+right_mx;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n+1));
    int tree_size = (1<<(h+1));
    
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        update(1,0,n-1,i,a[i]);
    }

    for(int i=0; i<tree_size; i++){
        sort(tree[i].begin(),tree[i].end());
    }

    cin >> m;
    int prvans=0;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        x^=prvans;
        y^=prvans;
        z^=prvans;
        prvans=query(1,0,n-1,x-1,y-1,z);
        cout << prvans << '\n';
    }
} 