///https://www.acmicpc.net/problem/17467에 제출했다가 시간초과 먹은 코드

#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <regex>
#include <deque>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

ll n,p,ck,ans=1;

ll fpow(ll a,ll b){
	ll ret=1;
	while(b){
		if(b%2){
			ret*=a; 
            ret%=p;
		}
		a=(a*a)%p; 
		b/=2; 
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> p;
    if(p==2){
        cout << 1;
        return 0;
    }
    if((p-n)%2){
        ck=-1;
    }
    else{
        ck=1;
    }
    ll y=p-n-1;
    if(n<=y){
        for(int i=2; i<=n; i++){
            ans*=i;
            ans%=p;
        }
        cout << ans%p;
        return 0;
    }
    for(int i=2; i<=y; i++){
        ans*=i;
        ans%=p;
    }
    ans=fpow(ans,p-2);
    ans%=p;
    ans*=ck;
    if(ans>=0){
        cout << ans;
    }
    else{
        cout << ans+p;
    }
	
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   