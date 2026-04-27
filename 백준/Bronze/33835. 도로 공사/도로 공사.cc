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

ll n,x[100000]={},y[100000]={};

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
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    double s=0.0;
    for(int i=0; i<n-1; i++){
        double dx=double(x[i+1]-x[i]),dy=double(y[i+1]-y[i]);
        s+=sqrt(dx*dx+dy*dy);
    }
    double dx=double(x[n-1]-x[0]);
    double dy=double(y[n-1]-y[0]);
    double d=sqrt(dx*dx+dy*dy);
    double ans=d<s?d:s;
    cout << fixed;
    cout.precision(4);
    cout << ans;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   