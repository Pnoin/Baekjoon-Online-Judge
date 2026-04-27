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
vector <int> tree[1050000];  //max val of n = 300000 --> max val of tree_size = 1048576

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
        return tree[node].size()-(lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin());
    }
    int left_mn=query(node*2,start,(start+end)/2,left,right,val);
    int right_mn=query(node*2+1,(start+end)/2+1,end,left,right,val);
    return left_mn+right_mn;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int h=(int)ceil(log2(n+1));
    int tree_size = (1<<(h+1));
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        update(1,0,n-1,i,temp);
    }

    for(int i=0; i<tree_size; i++){
        sort(tree[i].begin(),tree[i].end());
    }

    for(int i=0; i<m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(query(1,0,n-1,x-1,x-1,y)){
            cout << 0 << '\n';
            continue;
        }
        cout << query(1,0,n-1,x,x+z-1,y) << '\n';
    }
} 