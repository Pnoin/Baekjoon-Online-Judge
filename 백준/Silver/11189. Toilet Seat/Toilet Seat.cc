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

string s;
int a1=0,a2=0,a3=0; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> s;
    char seat1=s[0],seat2=s[0],seat3=s[0];
    for(int i=1; i<s.size(); i++){
        char pref=s[i];
        if(seat1!=pref){
            a1++;
            seat1=pref;
        }
        if(seat1!='U'){
            a1++;
            seat1='U';
        }
        if(seat2!=pref){
            a2++;
            seat2=pref;
        }
        if(seat2!='D'){
            a2++;
            seat2='D';
        }
        if(seat3!=pref){
            a3++;
            seat3=pref;
        }
    }
    cout << a1 << '\n' << a2 << '\n' << a3;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   