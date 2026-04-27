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

int t;

int adjust(int t,int dh,int dm){
    int h=t/100,m=t%100;
    m+=dm;
    h+=dh+m/60;
    m=(m%60+60)%60;
    h=(h%24+24)%24;
    return h*100+m;
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

    cin >> t;
    struct Zone{
        string label; 
        int dh,dm; 
    };
    vector <Zone> zones={{"Ottawa",0,0},{"Victoria",-3,0},{"Edmonton",-2,0},{"Winnipeg",-1,0},{"Toronto",0,0},{"Halifax",1,0},{"St. John's",1,30}};
    for(auto &z:zones){
        cout << adjust(t, z.dh, z.dm) << " in " << z.label << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   