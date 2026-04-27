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
ll cnt=0,cnt2=0;

void merge_sort(vector <ll> &a, vector <ll> &tree, int start, int end) {
    if(start<end) {
        merge_sort(a,tree,start, (start+end)/2);
        merge_sort(a,tree,(start+end)/2+1, end);
        int left=start, right=(start+end)/2+1, idx=start;
        while (left<=(start+end)/2 || right<=end) {
            if (right>end || (left<=(start+end)/2 && a[left]<a[right])) {
                tree[idx++] = a[left++];
            }
            else {
                cnt+=((start+end)/2-left+1);
                tree[idx++] = a[right++];
            }
        }
        for(int i=start; i<=end; i++){
            a[i]=tree[i];
        }
    }
}

void merge_sort2(vector <ll> &b, vector <ll> &tree2, int start, int end) {
    if(start<end) {
        merge_sort2(b,tree2,start, (start+end)/2);
        merge_sort2(b,tree2,(start+end)/2+1, end);
        int left=start, right=(start+end)/2+1, idx=start;
        while (left<=(start+end)/2 || right<=end) {
            if (right>end || (left<=(start+end)/2 && b[left]<=b[right])) {
                tree2[idx++] = b[left++];
            }
            else {
                cnt2+=((start+end)/2-left+1);
                tree2[idx++] = b[right++];
            }
        }
        for(int i=start; i<=end; i++){
            b[i]=tree2[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);
    vector <ll> tree(n);
    vector <ll> tree2(n);
    vector <pair<ll,ll>> v;
    vector <pair<ll,ll>> u;
    for(int i=0; i<n; i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
        u.push_back({y,x});
    }
    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    for(int i=0; i<n; i++){
        a[i]=v[i].second;
        b[i]=u[i].second;
    }
    merge_sort(a,tree,0,n-1);
    merge_sort2(b,tree2,0,n-1);
    cout << min(cnt,cnt2);
}