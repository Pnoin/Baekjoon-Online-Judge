#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef complex<long double> cpx;
const double PI = acos(-1); 

ll n,arr[100005]={},dp[100005][2]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[1][1]=arr[1];
    for(int i=2; i<=n; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+arr[i];
    }
    cout << min(dp[n][0],dp[n][1]);
}