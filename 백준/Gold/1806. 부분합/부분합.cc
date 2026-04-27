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
typedef complex<double> cpx;
const double PI = acos(-1); 

int n,s;
ll dp[100005]={};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	for(int i=1; i<=n; i++){
		cin >> dp[i];
	}
    int hi=1,lo=1,cnt=1e9;
    ll total=dp[1]; 
    while(true){
        if(lo>hi || hi>n){
            break;
        }
        if(total<s){
            hi++;
            total+=dp[hi];
        }
        else{
            cnt=min(cnt,hi-lo+1);
            total-=dp[lo];
            lo++;
        }
    }
    if(cnt==1e9){
        cout << 0;
        return 0;
    }
    ///cout << hi << ' ' << lo << '\n';
    cout << cnt;
}