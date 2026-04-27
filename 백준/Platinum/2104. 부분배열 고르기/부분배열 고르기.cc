/* 
    히스토그램과 같은데 이번에는 구간 내의 최솟값에 구간의 크기를 곱하는게 아니라 구간 내의 모든 값들의 합을 곱해야함.
    때문에 누적합 배열을 하나 만들어서 구간 내 합을 빠르게 구하고 최솟값 ans를 구하도록 함.
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

int n;
ll prefix_sum[100005]={};

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
    ll idx=query(a,tree,1,0,n-1,start,end), ans=(prefix_sum[end]-prefix_sum[start]+a[start])*a[idx];
    /*
        prefix_sum[end]-prefix_sum[start-1]이 아니라 prefix_sum[end]-prefix_sum[start]+a[start]를 한 이유는
        start가 만약 0일 경우, out of index 오류가 뜰 걸 감안했음
        따로 조건문 만들어서 0인 경우를 따로 처리하는게 귀찮았음.
    */
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
    cin >> a[0];
    prefix_sum[0]=a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        prefix_sum[i]=prefix_sum[i-1]+a[i];
    }
    seg_tree(a,tree,1,0,n-1);
    cout << mx(a,tree,0,n-1);
}