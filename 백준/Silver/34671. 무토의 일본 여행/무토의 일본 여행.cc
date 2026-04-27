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

ll n,m,q,a,b,c;
unordered_map <ll,ll> mp;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> n >> m >> q;
    mp.reserve(m*2);
    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        ll k1=a*(n+1)+b,k2=b*(n+1)+a;
        if(mp.find(k1)==mp.end()){
            mp.emplace(k1,c);
        }
        else{
            if(c<mp.find(k1)->second){
                mp.find(k1)->second=c;
            }
        }
        if(mp.find(k2)==mp.end()){
            mp.emplace(k2,c);
        }
        else{
            if(c<mp.find(k2)->second){
                mp.find(k2)->second=c;
            }
        }
    }
    for(int i=0; i<q; i++){
        ll s,e;
        cin >> s >> e;
        ll k=(ll)s*(n+1)+e;
        if(mp.find(k)==mp.end()){
            cout << -1 << '\n';
        }
        else{
            cout << mp.find(k)->second << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

