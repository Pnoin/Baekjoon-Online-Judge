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
ld phi=(1.0+sqrt(5.0))/2.0;

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
        ld a,b;
        cin >> a >> b;
        if(a==0 || b==0){
            cout << "not" << '\n';
            continue;
        }
        ld r=a/b;
        if(r<1.0){
            r=1.0/r;
        }
        ld low=phi*0.99,high=phi*1.01;
        if(r>=low && r<=high){
            cout << "golden" << '\n';
        } 
        else{
            cout << "not" << '\n';
        }
    }

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

