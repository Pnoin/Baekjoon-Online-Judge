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
typedef __int128_t li;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int n,m;
ld x[1005]={},y[1005]={};

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
    cin >> m;
    for(int i=0; i<m; i++){
        int p,arr[20]={}; 
        cin >> p;
        for(int j=0; j<p; j++){
            cin >> arr[j];
        }
        ld ans=0;
        for(int j=1; j<p; j++){
            ans+=hypot(x[arr[j]]-x[arr[j-1]],y[arr[j]]-y[arr[j-1]]);
        }
        cout << fixed;
        cout.precision(0);
        cout << ans << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   