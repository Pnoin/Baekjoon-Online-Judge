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

int n,o,t_min=1e9,t_max=-1e9;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    int n,o;
    cin >> n >> o;

    int q_max=o/(n-1);
    int q_min=(o-(n-1)+(n-2))/(n-1);  
    if(q_min<0){
        q_min=0;
    }
    for(int q=q_min; q<=q_max; q++){
        int r=o-q*(n-1);
        if(r<0 || r>=n){
            continue;
        }
        int t=q*n+r;
        if(t-q==o){
            t_min=min(t_min,t);
            t_max=max(t_max,t);
        }
    }
    cout << t_min << ' ' << t_max;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   