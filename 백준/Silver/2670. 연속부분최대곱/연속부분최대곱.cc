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

int n;
ld arr[10005]={},dp[10005]={},total=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0]=arr[0];
    total=arr[0];
    for(int i=1; i<n; i++){
        dp[i]=max(arr[i],arr[i]*dp[i-1]);
        total=max(total,dp[i]);
    }
    cout << fixed;
    cout.precision(3);
    cout << total;
}