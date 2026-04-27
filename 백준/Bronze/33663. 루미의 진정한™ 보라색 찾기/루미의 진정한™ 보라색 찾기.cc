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

ld hx,hy,sx,sy,vx,vy,r,g,b,v,s,h;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> hx >> hy >> sx >> sy >> vx >> vy >> r >> g >> b;  
    v=max({r,g,b});
    s=255.0*(v-min({r,g,b}))/v;
    if(r==max({r,g,b})){
        h=60.0*(g-b)/(v-min({r,g,b}));
    } 
    else if(g==max({r,g,b})){
        h=120.0+60.0*(b-r)/(v-min({r,g,b}));
    } 
    else if(b==max({r,g,b})){
        h=240.0+60.0*(r-g)/(v-min({r,g,b}));
    }
    if(h<0){
        h+=360;
    }
    if(hx<=h && h<=hy && sx<=s && s<=sy && vx<=v && v<=vy){
        cout << "Lumi will like it.";
    }
    else{
        cout << "Lumi will not like it.";
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}