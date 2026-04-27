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

int k,n;
ll lengths[10005]={},lo=1,hi=0,ans=0,mid;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> k >> n; 
    for(int i=0; i<k; i++){
        cin >> lengths[i]; 
    }
    for(int i=0; i<k; i++){
        hi=max(hi,lengths[i]); 
    }
    while(lo<=hi){
        mid=(lo+hi)/2;
        ll cnt=0;
        for(int i=0; i<k; i++){
            cnt+=lengths[i]/mid; 
        }
        if(cnt>=n){
            ans=mid;
            lo=mid+1; 
        }
        else{
            hi=mid-1; 
        }
    }
    cout << ans; 

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   