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
ll cnt=0;

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
        for(int i=start; i<=end; i++)
            a[i]=tree[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n;
        cnt=0;
        if(n==0){
            break;
        }
        vector <ll> a(n);
        vector <ll> tree(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        merge_sort(a,tree,0,n-1);
        if(cnt%2==1){
            cout << "Marcelo" << '\n';
        }
        else{
            cout << "Carlos" << '\n';
        }
    }
}