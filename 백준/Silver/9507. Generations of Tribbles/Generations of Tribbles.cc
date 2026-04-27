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

int t;
ll dp[105]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i=0; i<t; i++){
        ll n;
        cin >> n;
        memset(dp,0,sizeof(dp));    
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        dp[4]=8;
        for(int j=5; j<=n; j++){
            dp[j]=dp[j-1]+dp[j-2]+dp[j-3]+dp[j-4];
        }
        cout << dp[n] << '\n';
    }
}