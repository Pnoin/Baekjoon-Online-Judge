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

int a,b,c,d,p,m,n;

int attacked(int t){
    int cnt=0;
    int cycle1=a+b;
    int cycle2=c+d;
    int r1=(t-1)%cycle1;
    if(r1 < a){
        cnt++;
    }
    int r2=(t-1)%cycle2;
    if(r2 < c){
        cnt++;
    }
    return cnt;
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

    cin >> a >> b >> c >> d >> p >> m >> n;
    cout << attacked(p) << '\n' << attacked(m) << '\n' << attacked(n) << '\n';

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   