/*
    이전 코드에서 찾았던 반례:
    10090번과 다르게 중복 입력이 가능함. 
    기존에 사용하던 inversion counting 코드는 중복 입력 처리를 제대로 하지 못했음
    예시로 2 1 1이 들어오면 2가 아니라 1을 출력했음. 
    이번에는 각 입력받는 숫자가 아니라 그들의 인덱스를 활용하는 방식으로 하여 중복입력된 숫자도 별개 처리가능하겠금 변경. 
    인덱스와 값 모두 저장하기 위해 그냥 벡터에서 pair 벡터로 변경.
*/
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
typedef pair <ll,ll> pll;

int n;
ll num, ans=0;

void seg_tree(vector <ll> &tree, int node, int start, int end){
    if(start==end){
        tree[node]=0;
    }
    else{
        seg_tree(tree,node*2,start,(start+end)/2);
        seg_tree(tree,node*2+1,(start+end)/2+1,end);
    }
}

void update(vector <ll> &tree, int node, int start, int end, int idx){
    if(idx < start || idx > end){
        return;
    }
    if(start==end){
        tree[node]=1;
        return; 
    }
    update(tree, node*2, start, (start+end)/2, idx);
    update(tree, node*2+1, (start+end)/2+1, end, idx);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left > end || start > right){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    ll left_s=query(tree,node*2,start,(start+end)/2,left,right);
    ll right_s=query(tree,node*2+1,(start+end)/2+1,end,left,right);
    return left_s + right_s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int h=(int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector <pll> a;
    vector <ll> tree(tree_size);
    for(int i=0; i<n; i++){
        cin >> num;
        a.push_back({num,i});
    }
    sort(a.begin(), a.end());
    seg_tree(tree,1,0,n-1);
    for(int i=0; i<n; i++){
      update(tree, 1, 0, n-1, a[i].second);
      ans+=query(tree, 1, 0, n-1, a[i].second+1, n-1);
    }
    cout << ans;
}