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

int n,a[1005]={},curr_phone,curr_batt,prev_cons;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    curr_phone=-1;
    curr_batt=0;
    prev_cons=0;
    for(int i=0; i<n; i++){
        int consume;
        if(a[i]!=curr_phone){
            consume=2;
            prev_cons=2;
            curr_phone=a[i];
        }
        else{
            consume=prev_cons*2;
            prev_cons=consume;
        }
        curr_batt+=consume;
        if(curr_batt>=100){
            curr_batt=0;
            curr_phone=-1;
            prev_cons=0;
        }
    }

    cout << curr_batt;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   