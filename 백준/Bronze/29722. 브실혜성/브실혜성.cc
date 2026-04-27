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

string today;
int n;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

    cin >> today >> n;
    ll year=stol(today.substr(0,4)),month=stol(today.substr(5,2)),day=stol(today.substr(8,2));
    ll total=year*360+(month-1)*30+(day-1);
    total+=n;
    int new_year=total/360,rem=total%360,new_month=rem/30+1, new_day=rem%30+1;
    cout << setw(4) << setfill('0') << new_year << '-' << setw(2) << setfill('0') << new_month << '-' << setw(2) << setfill('0') << new_day << "\n";

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   