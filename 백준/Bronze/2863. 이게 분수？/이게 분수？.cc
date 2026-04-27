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

int a,b,c,d,answer=0;
double f[4]={};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> a >> b >> c >> d;
    f[0]=double(a)/double(c)+double(b)/double(d);
    f[1]=double(c)/double(d)+double(a)/double(b);
    f[2]=double(d)/double(b)+double(c)/double(a);
    f[3]=double(b)/double(a)+double(d)/double(c);
    double best=f[0];
    for(int k=1; k<4; k++){
        if(f[k]>best){
            best=f[k];
            answer=k;
        }
    }
    cout << answer;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   