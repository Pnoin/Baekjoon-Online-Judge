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

int t,ds[105]={},answ[105]={};

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
    for(int i=0; i<t; i++){
        cin >> ds[i];
    }
    for(int i=0; i<t; i++){
        int d=ds[i],m=1+4*d,k=(int)sqrt(m);
        while((k+1)*(k+1)<=m){
            k++;
        }
        while(k*k>m){
            k--;
        }
        int t=(k-1)/2;
        while((t+1)*(t+1)+(t+1)<=d){
            t++;
        }
        while(t*t+t>d){
            t--;
        }
        answ[i]=t;
    }
    for(int i=0; i<t; i++){
        cout << answ[i] << '\n';
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   