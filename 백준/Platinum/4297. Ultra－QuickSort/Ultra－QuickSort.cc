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
ll cnt=0, arr[500005]={}, temp[500005]={};;

void merge_sort(ll a[], ll tree[], int start, int end) {
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
        if(n==0){
            return 0;
        }
        cnt=0;
        memset(arr,0,sizeof(arr));
        memset(temp,0,sizeof(temp));
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        merge_sort(arr,temp,0,n-1);
        cout << cnt << '\n';
    }
}