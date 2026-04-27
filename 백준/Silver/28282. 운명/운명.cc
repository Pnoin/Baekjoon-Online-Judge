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

ll a,x,k,lcnt[10005]={},rcnt[10005]={},total=0,same=0; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> x >> k;
	for(int i=0; i<x; i++){
		cin >> a; 
		lcnt[a]++; 
	}
	for(int i=0; i<x; i++){
		cin >> a; 
		rcnt[a]++; 
	}
	total=x*x; 
	for(int i=1; i<=k; i++){
		same+=lcnt[i]*rcnt[i]; 
	}
	cout << total-same;

    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   

