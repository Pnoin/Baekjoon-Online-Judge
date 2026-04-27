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

int n,m,arr[100005]={},dp[100005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<m; j++){
            dp[i]+=arr[i+j];
        }
    }
    sort(dp,dp+(n-m+1));
    cout << dp[n-m];
}