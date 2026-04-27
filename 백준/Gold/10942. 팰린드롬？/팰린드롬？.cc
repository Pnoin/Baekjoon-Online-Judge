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

int n,m,arr[2005]={},dp[2005][2005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){   ///1개 = 팰린드롬
        cin >> arr[i];
        dp[i][i]=1;
    }
    for(int i=0; i<n-1; i++){
        if(arr[i]==arr[i+1]){     /// 0 0도 팰린드롬
            dp[i][i+1]=1;
            dp[i+1][i]=1;
        }
    }
    for(int i=n-2; i>=0; i--){       /// 0(1)0     1(0(1)0)1     0(1(0(1)0)1)0
		for(int j=i+1; j<n; j++){
			if (arr[i]==arr[j] && dp[i+1][j-1]==1){
				dp[i][j]=1;
			}
		}
	}
    cin >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        cout << dp[x-1][y-1] << '\n';
    }
} 