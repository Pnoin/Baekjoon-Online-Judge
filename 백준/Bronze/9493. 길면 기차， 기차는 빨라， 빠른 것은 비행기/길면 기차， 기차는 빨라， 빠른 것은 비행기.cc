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

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    while(true){
        int m,a,b;
        cin >> m >> a >> b;
        if(m==0 && a==0 && b==0){
            break;
        }
        double diff_hours=double(m)*(1.0/a-1.0/b);
        double diff_seconds_d=diff_hours*3600.0;
        ll diff_seconds=(ll)(diff_seconds_d+0.5); 
        cout << diff_seconds/3600 << ':' << setw(2) << setfill('0') << (diff_seconds%3600)/60 << ':' << setw(2) << setfill('0') << (diff_seconds%3600)%60 << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   