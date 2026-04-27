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

int t,m,n,p;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> m >> n >> p;
        vector <vector <int>> S(m+1,vector <int> (n));
        for(int i=1; i<=m; i++){
            for(int j=0; j<n; j++){
                cin >> S[i][j];
            }
        }
        ll extra=0;
        for(int j=0; j<n; j++){
            int mx=0;
            for(int i=1; i<=m; i++){
                mx=max(mx,S[i][j]);
            }
            if(S[p][j]<mx){
                extra+=(mx-S[p][j]);
            }
        }
        cout << "Case #" << i << ": " << extra << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   