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

int n;
ll t,best_wait=1e16;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n >> t;
    for(int i=0; i<n; i++){
        ll S,I,C,departure;
        cin >> S >> I >> C;
        if(t<=S){
            departure=S;
        } 
        else{
            ll k=(t-S+I-1)/I;  
            if(k>=C){
                continue; 
            }
            departure=S+k*I;
        }
        ll wait=departure-t;
        best_wait=min(best_wait,wait);
    }
    if(best_wait==(ll)1e16){
        cout << -1;
    } 
    else{
        cout << best_wait;
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   