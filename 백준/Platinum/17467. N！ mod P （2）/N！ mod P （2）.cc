/*
    https://www.acmicpc.net/board/view/160580
    https://www.nayuki.io/page/barrett-reduction-algorithm
    그 외의 전체적인 접근 방법(윌슨의 정리 + 페르마의 소정리)은 티스토리에 정리 예정
*/

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

ll n,p,ck,ans=1,mu;                       

ll barrett(__int128 x){            
    ll q=(ll)((x*mu)>>64);
    ll r=(ll)(x-(__int128)q*p);
    if(r>=p){
        r-=p;
    }
    return r;
}

ll fmul(ll a,ll b){ 
    return barrett((__int128)a*b); 
}

ll fpow(ll a,ll b){
    a%=p; 
    ll ret=1%p;
    while(b){ 
        if(b%2){
            ret=fmul(ret,a); 
        }
        a=fmul(a,a); 
        b>>=1; 
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
    mu=(ll)((__int128(1)<<64)/p); 
    ll y=p-n-1;
    if(n<=y){
        for(int i=2; i<=n; i++){
            ans=fmul(ans,i);
        }
        cout << ans;
        return 0;
    }
    for(int i=2; i<=y; i++){
        ans=fmul(ans,i);
    }
    ans=fpow(ans,p-2);
    if(ck==1){
        cout << ans;
    }
    else{
        cout << p-ans;
    }
	
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   