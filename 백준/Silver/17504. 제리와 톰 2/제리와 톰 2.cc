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

int n,a[20]={};

ll gcd(ll x,ll y){
    ll t;
    while(y){
        t=x%y;
        x=y;
        y=t;
    }
    return x;
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

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    ll num=a[n],den=1;
    for(int i=n-1; i>=1; i--){
        ll new_num=a[i]*num+den,new_den=num;
        num=new_num;
        den=new_den;
    }
    ll P=num-den,Q=num,g=gcd(P,Q);
    P/=g;
    Q/=g;
    cout << P << ' ' << Q;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   