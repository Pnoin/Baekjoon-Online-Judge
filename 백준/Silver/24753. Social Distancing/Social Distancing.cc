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

int n,s,arr[1005]={},ans=0;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*  
    clock_t start,finish;
    double duration;
    start=clock();
    */

	cin >> s >> n;  
	for(int i=0; i<n; i++){
		cin >> arr[i]; 
	}
	for(int i=0; i<n-1; i++){
		if(arr[i+1]-arr[i]-1>=1){
			ans=ans+(arr[i+1]-arr[i]-1-1)/2; 
		}
	}
	if(arr[0]+s-arr[n-1]-1>=1){
		ans=ans+(arr[0]+s-arr[n-1]-1-1)/2; 
	}
	cout << ans; 
	
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}   