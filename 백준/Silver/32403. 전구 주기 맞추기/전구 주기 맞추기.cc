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

int n,t;
ll ans=0;
vector <int> v; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> n >> t; 
	for(int i=1; i*i<=t; i++){
		if(t%i){
            continue;
		}
        v.push_back(i); 
        if(i!=t/i){
            v.push_back(t/i); 
        }
	}
	for(int i=0; i<n; i++){
		int a,mn=1e9;
		cin >> a;  
		for(int j=0; j<v.size(); j++){
            mn=min(mn,abs(a-v[j]));
		}
		ans+=mn; 
	}
	cout << ans; 
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   